param([string]$wa, [string]$ac, [string]$gen)
c++ "$wa.cpp" -o "$wa" -O2 --std=c++20
c++ "$ac.cpp" -o "$ac" -O2 --std=c++20
c++ "$gen.cpp" -o "$gen" -O2 --std=c++20

$time = 0
while ($true) {
  & "./$gen" > input
  & Get-Content "input" | & "./$ac"  > ac.out
  & Get-Content "input" | & "./$wa" > wa.out
  $acout = Get-Content ac.out
  $waout = Get-Content wa.out
  if (Compare-Object $acout $waout) {
    Get-Content "input"
    Write-Host "====== AC ======"
    Get-Content "ac.out"
    Write-Host "====== WA ======"
    Get-Content "wa.out"
    break
  } else {
    $time = $time + 1
    Write-Host $time
  }
}
Remove-Item "$ac.exe"
Remove-Item "$wa.exe"
Remove-Item "$gen.exe"