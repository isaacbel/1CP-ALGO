Function ElemFibo(N:Longint): Boolean;
// donne vrai si N est un element de la suite de Fibonacci
// on ne prendra que les 45 premiers elements de la suite, donc N<=45
Var
  T: tab1D;
  i: Integer;
  Trouv: Boolean;
//-------------------------------
{$i SuiteFibo}
//-------------------------------
Begin //ElemFibo
  SuitFibo(45,T,tai);
  Trouv := False;
  i := 1;
  Repeat
    If T[i]= N Then Trouv := True;
    i := i+1;
  Until (Trouv=True) Or (i>tai);
  ElemFibo := Trouv;
End; //ElemFibo