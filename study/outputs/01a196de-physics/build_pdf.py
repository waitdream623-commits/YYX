from pathlib import Path
import math
import openpyxl
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import A5
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.platypus import Table,TableStyle,Paragraph
from reportlab.lib.styles import ParagraphStyle
from reportlab.lib import colors
from pypdf import PdfReader
base=Path('D:/c/code/yy/study/outputs/01a196de-physics')
out=base/'物理实验_A5表格与曲线.pdf'
pdfmetrics.registerFont(TTFont('CN','C:/Windows/Fonts/simhei.ttf'))
wb=openpyxl.load_workbook(base/'物理实验1_增加T列.xlsx',data_only=True)
s=wb['波动参考']
c=canvas.Canvas(str(out),pagesize=A5)
c.setTitle('RC、RL实验数据表与特性曲线 - A5打印版')
w,h=A5
left=22; width=w-44
style=ParagraphStyle('header',fontName='CN',fontSize=8,leading=10,alignment=1)
def text(x,y,t,size=9):
 c.setFont('CN',size);c.setFillColor(colors.black);c.drawString(x,y,t)
def plot(rows,col,component,title,bottom,lo,hi,yticks):
 x0=left+36; y0=bottom; pw=width-43; ph=79
 xmax=5 if rows[-1][0]<=5 else 40
 xticks=[0,1,2,3,4,5] if xmax==5 else [0,10,20,30,40]
 def xy(x,y):return x0+x/xmax*pw,y0+(y-lo)/(hi-lo)*ph
 text(left,bottom+99,title,10)
 c.setLineWidth(.35)
 for y in yticks:
  yy=xy(0,y)[1];c.setStrokeColor(colors.HexColor('#d8d8d8'));c.line(x0,yy,x0+pw,yy)
  c.setFont('Helvetica',7.5);c.setFillColor(colors.black);c.drawRightString(x0-5,yy-2.5,f'{y:g}')
 for x in xticks:
  xx=xy(x,lo)[0];c.setStrokeColor(colors.HexColor('#dddddd'));c.line(xx,y0,xx,y0+ph)
  c.setFont('Helvetica',7.5);c.setFillColor(colors.black);c.drawCentredString(xx,y0-11,f'{x:g}')
 c.setStrokeColor(colors.black);c.setLineWidth(.6);c.rect(x0,y0,pw,ph)
 pts=[xy(r[0],r[col]) for r in rows]
 path=c.beginPath();path.moveTo(*pts[0])
 for p in pts[1:]:path.lineTo(*p)
 c.setLineWidth(.9);c.drawPath(path)
 for p in pts:c.circle(*p,1.7,fill=1,stroke=0)
 c.setFont('Helvetica',8);c.drawCentredString(x0+pw/2,y0-24,'f (kHz)')
 label=f'U_{component}/U' if col==3 else f'φ_{component} (rad)'
 text(x0,y0+ph+5,label,8)
for page,(head,end,circuit,component) in enumerate([(1,15,'RC','R'),(18,29,'RC','C'),(32,43,'RL','R'),(46,57,'RL','L')],1):
 rows=[[s.cell(r,k).value for k in range(1,8)] for r in range(head+1,end+1)]
 name={'R':'电阻 R','C':'电容 C','L':'电感 L'}[component]
 text(left,h-30,f'表{page}  {circuit} 串联电路：{name}',13)
 text(left,h-47,'幅频与相频特性',9)
 c.setStrokeColor(colors.black);c.setLineWidth(.6);c.line(left,h-55,w-left,h-55)
 headers=['f<br/>(kHz)',f'U<sub>{component}</sub><br/>Vpp (V)','U<br/>Vpp (V)',f'U<sub>{component}</sub>/U',f'φ<sub>{component}</sub><br/>(rad)','ΔT<br/>(ms)','T<br/>(ms)']
 data=[[Paragraph(x,style) for x in headers]]
 for r in rows:
  data.append([f'{r[0]:g}',f'{r[1]:.3f}',f'{r[2]:.2f}',f'{r[3]:.4f}',f'{r[4]:.4f}',f'{r[5]:.4f}',f'{r[6]:.4f}'])
 table=Table(data,colWidths=[width*v for v in [.105,.15,.14,.15,.155,.15,.15]],rowHeights=[27]+[15]*len(rows))
 table.setStyle(TableStyle([('FONTNAME',(0,1),(-1,-1),'Helvetica'),('FONTSIZE',(0,1),(-1,-1),8),('ALIGN',(0,0),(-1,-1),'CENTER'),('VALIGN',(0,0),(-1,-1),'MIDDLE'),('BACKGROUND',(0,0),(-1,0),colors.HexColor('#eeeeee')),('GRID',(0,0),(-1,-1),.35,colors.HexColor('#888888')),('TOPPADDING',(0,0),(-1,-1),2),('BOTTOMPADDING',(0,0),(-1,-1),2)]))
 tw,th=table.wrap(width,300);table.drawOn(c,left,h-67-th)
 text(left,h-67-th-13,'模型参考数据（非实测）；T = 1/f；ΔT 保留原正负号。',7.5)
 plot(rows,3,component,'幅频特性',163,0,1.05,[0,.25,.5,.75,1])
 if component=='R' and circuit=='RL' or component=='C':lo,hi,ticks=-1.4,.2,[-1.2,-.8,-.4,0]
 else:lo,hi,ticks=0,1.6,[0,.4,.8,1.2,1.6]
 plot(rows,4,component,'相频特性',35,lo,hi,ticks)
 c.setFont('Helvetica',6.5);c.drawRightString(w-left,7,f'{page} / 4')
 c.showPage()
c.save()
r=PdfReader(str(out));assert len(r.pages)==4
for p in r.pages:
 assert abs(float(p.mediabox.width)-w)<.1 and abs(float(p.mediabox.height)-h)<.1
 assert '模型参考' in p.extract_text()
print(out)
print('Verified: 4 A5 pages, all 47 data rows, paired amplitude and phase plots.')
