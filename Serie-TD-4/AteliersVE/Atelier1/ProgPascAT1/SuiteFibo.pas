Procedure SuitFibo(N:Longint; Var T:Tab1D; Var Tai:Tind);
//donne une table qui contient les elements de la suite de fibonacci
// Max 45 elements
Var
  i: Integer;
//-------------------------------
{$i fibo}
//-------------------------------
Begin
  t[1] := 1;
  t[2] := 1;
  For i:=3 To N Do
    t[i] := Fibo(i);
  Tai := N;
End; //SuitFibo