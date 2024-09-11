Program exo4_S4 ;
Uses Crt;
Function NBPARF(N:Longint): Boolean;
Var
  p,i : Longint;
  k: Boolean;
Begin
  p := 1 ;
  k := False;
  For i:=2 To (N Div 2) Do
    Begin
      If (N Mod i = 0) Then
        p := p + i ;
    End;
  If N=p Then k := True
  Else k := False;
  NBPARF := k;
End;
//-------------------------------------------
Var
  j,N : Longint;
Begin
  Writeln('Enter N ');
  Readln(N);
  For j:=2 To N Do
    Begin
      If (NBPARF(j) = True ) Then Write(j,' ');
    End;
  Readln;
End.
