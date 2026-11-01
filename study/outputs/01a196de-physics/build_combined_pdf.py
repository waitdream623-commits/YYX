from pathlib import Path
import openpyxl
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import A5,landscape
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.platypus import Table,TableStyle,Paragraph
from reportlab.lib.styles import ParagraphStyle
from reportlab.lib import colors
from pypdf import PdfReader
base=Path('D:/c/code/yy/study/outputs/01a196de-physics')
out=base/'物理实验_A5合并打印版.pdf'
pdfmetrics.registerFont(TTFont('CN','C:/Windows/Fonts/simhei.ttf'))
s=openpyxl.load_workbook(base/'物理实验1_增加T列.xlsx',data_only=True)['波动参考']
w,h=landscape(A5);margin=18;gutter=14;cw=(w-2*margin-gutter)/2
c=canvas.Canvas(str(out),pagesize=(w,h));c.setTitle('RC、RL特性曲线合并对照 - A5横向打印版')
style=ParagraphStyle('header',fontName='CN',fontSize=7.3,leading=8.5,alignment=1)
def text(x,y,t,size=9):
 c.setFillColor(colors.black);c.setFont('CN',size);c.drawString(x,y,t)
def table(x,rows,comp):
 text(x,h-45,{'R':'电阻 R','C':'电容 C','L':'电感 L'}[comp],9)
 hdr=['f<br/>(kHz)',f'U<sub>{comp}</sub><br/>Vpp (V)','U<br/>Vpp (V)',f'U<sub>{comp}</sub>/U',f'φ<sub>{comp}</sub><br/>(rad)','ΔT<br/>(ms)','T<br/>(ms)']
 data=[[Paragraph(t,style) for t in hdr]]
 for r in rows:data.append([f'{r[0]:g}',f'{r[1]:.3f}',f'{r[2]:.2f}',f'{r[3]:.4f}',f'{r[4]:.4f}',f'{r[5]:.4f}',f'{r[6]:.4f}'])
 widths=[cw*.095]+[cw*.905/6]*6
 t=Table(data,colWidths=widths,rowHeights=[24]+[12]*len(rows))
 t.setStyle(TableStyle([('FONTNAME',(0,1),(-1,-1),'Helvetica'),('FONTSIZE',(0,1),(-1,-1),7.2),('ALIGN',(0,0),(-1,-1),'CENTER'),('VALIGN',(0,0),(-1,-1),'MIDDLE'),('BACKGROUND',(0,0),(-1,0),colors.HexColor('#eeeeee')),('GRID',(0,0),(-1,-1),.3,colors.HexColor('#888888')),('LEFTPADDING',(0,0),(-1,-1),1),('RIGHTPADDING',(0,0),(-1,-1),1),('TOPPADDING',(0,0),(-1,-1),1),('BOTTOMPADDING',(0,0),(-1,-1),1)]))
 tw,th=t.wrap(cw,300);t.drawOn(c,x,h-53-th)
 return h-53-th

def plot(x,series,col,xmax):
 text(x,145,'幅频特性（两条曲线合并）' if col==3 else '相频特性（两条曲线合并）',9)
 x0=x+29;y0=36;pw=cw-36;ph=83
 lo,hi,ticks=(0,1.05,[0,.25,.5,.75,1]) if col==3 else (-1.6,1.6,[-1.6,-.8,0,.8,1.6])
 def xy(a,b):return x0+a/xmax*pw,y0+(b-lo)/(hi-lo)*ph
 c.setLineWidth(.3)
 for v in ticks:
  yy=xy(0,v)[1];c.setStrokeColor(colors.HexColor('#dddddd'));c.line(x0,yy,x0+pw,yy)
  c.setFillColor(colors.black);c.setFont('Helvetica',7);c.drawRightString(x0-4,yy-2.5,f'{v:g}')
 for v in ([0,1,2,3,4,5] if xmax==5 else [0,10,20,30,40]):
  xx=xy(v,lo)[0];c.setStrokeColor(colors.HexColor('#dddddd'));c.line(xx,y0,xx,y0+ph)
  c.setFillColor(colors.black);c.setFont('Helvetica',7);c.drawCentredString(xx,y0-10,f'{v:g}')
 c.setStrokeColor(colors.black);c.setLineWidth(.55);c.rect(x0,y0,pw,ph)
 text(x0,123,'U / U' if col==3 else 'φ (rad)',7)
 for j,(comp,rows) in enumerate(series):
  c.setStrokeColor(colors.black);c.setFillColor(colors.black);c.setLineWidth(.8);c.setDash([] if j==0 else [3,2])
  pts=[xy(r[0],r[col]) for r in rows];p=c.beginPath();p.moveTo(*pts[0])
  for pt in pts[1:]:p.lineTo(*pt)
  c.drawPath(p);c.setDash([])
  for px,py in pts:
   if j==0:c.circle(px,py,1.45,fill=1,stroke=0)
   else:c.rect(px-1.5,py-1.5,3,3,fill=0,stroke=1)
  lx=x+cw-103+j*52;ly=133
  c.setDash([] if j==0 else [3,2]);c.line(lx,ly,lx+13,ly);c.setDash([])
  if j==0:c.circle(lx+6.5,ly,1.5,fill=1,stroke=0)
  else:c.rect(lx+5,ly-1.5,3,3,fill=0,stroke=1)
  text(lx+17,ly-2.5,f'U_{comp}' if col==3 else f'φ_{comp}',7)
 c.setFont('Helvetica',7.5);c.drawCentredString(x0+pw/2,y0-22,'f (kHz)')
for page,(name,groups,xmax) in enumerate([('RC',[(1,15,'R'),(18,29,'C')],5),('RL',[(32,43,'R'),(46,57,'L')],40)],1):
 text(margin,h-23,f'{name} 串联电路：数据表与合并特性曲线',12)
 series=[];bottom=[]
 for j,(head,end,comp) in enumerate(groups):
  rows=[[s.cell(r,k).value for k in range(1,8)] for r in range(head+1,end+1)]
  series.append((comp,rows));bottom.append(table(margin+j*(cw+gutter),rows,comp))
 text(margin,min(bottom)-12,'模型参考数据（非实测）；T = 1/f；ΔT 保留原正负号。',7)
 plot(margin,series,3,xmax);plot(margin+cw+gutter,series,4,xmax)
 c.setFont('Helvetica',6);c.drawRightString(w-margin,6,f'{page} / 2');c.showPage()
c.save()
r=PdfReader(str(out));assert len(r.pages)==2
for p in r.pages:
 assert abs(float(p.mediabox.width)-w)<.1 and abs(float(p.mediabox.height)-h)<.1
 assert '两条曲线合并' in p.extract_text()
print(out)
