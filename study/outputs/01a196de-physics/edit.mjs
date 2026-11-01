import fs from 'node:fs/promises';
import {FileBlob, SpreadsheetFile} from '@oai/artifact-tool';
const dir='D:/c/code/yy/study/outputs/01a196de-physics';
const wb=await SpreadsheetFile.importXlsx(await FileBlob.load(dir+'/source.xlsx'));
console.log((await wb.inspect({kind:'sheet',include:'id,name'})).ndjson);
await fs.writeFile(dir+'/before.png',new Uint8Array(await (await wb.render({sheetName:'波动参考',range:'A1:G15',scale:1.5})).arrayBuffer()));
const sh=wb.worksheets.getItem('波动参考');
const groups=[[1,15,'R'],[18,29,'C'],[32,43,'R'],[46,57,'L']];
const original=sh.getRange('A1:F69').values;
for(const [h,end,component] of groups){
 sh.getRange(`G${h}:G${end}`).copyFrom(sh.getRange(`F${h}:F${end}`),'all');
 sh.getRange(`A${h}:G${h}`).values=[['f (kHz)',`U_${component} / Vpp (V)`,'U / Vpp (V)',`U_${component}/U`,`φ_${component} (rad)`,'ΔT (ms)','T (ms)']];
 sh.getRange(`F${h+1}:F${end}`).values=original.slice(h,end).map(r=>[r[5]/1000]);
 sh.getRange(`F${h+1}:G${end}`).setNumberFormat('0.0000');
 sh.getRange(`G${h+1}:G${end}`).formulas=Array.from({length:end-h},(_,i)=>[`=1/A${h+i+1}`]);
 sh.getRange(`E${h+1}:E${end}`).formulas=Array.from({length:end-h},(_,i)=>[`=2*PI()*F${h+i+1}/G${h+i+1}`]);
}
sh.getRange('B1:C57').format.columnWidth=21;
sh.getRange('D1:G57').format.columnWidth=16;
wb.recalculate();
for(const [h,end] of groups){
 const v=sh.getRange(`A${h+1}:G${end}`).values;
 for(let i=0;i<v.length;i++){
  if(Math.abs(v[i][6]-1/v[i][0])>1e-10)throw Error('T mismatch');
  if(Math.abs(v[i][4]-original[h+i][4])>1e-10)throw Error('phase mismatch');
 }
}
console.log((await wb.inspect({kind:'table',range:'波动参考!A1:G4',include:'values,formulas',tableMaxRows:4,tableMaxCols:7})).ndjson);
console.log((await wb.inspect({kind:'match',searchTerm:'#REF!|#DIV/0!|#VALUE!|#NAME\\?|#NUM!|#NULL!',options:{useRegex:true,maxResults:10}})).ndjson);
for(const [h,end] of groups){
 await fs.writeFile(dir+`/after-${h}.png`,new Uint8Array(await (await wb.render({sheetName:'波动参考',range:`A${h}:G${Math.min(end,h+4)}`,scale:1.5})).arrayBuffer()));
}
await (await SpreadsheetFile.exportXlsx(wb)).save(dir+'/物理实验1_增加T列.xlsx');
console.log('Saved');
