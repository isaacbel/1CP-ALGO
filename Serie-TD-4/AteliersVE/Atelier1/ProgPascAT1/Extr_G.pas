Function Extr_G (N, P:Longint): Longint;
// ------------------------------------------
// Extrait P positions a gauche de N
// ------------------------------------------
Var NP1:integer;
//-------------------------------
{$i NbPos}
{$i puissance}
//-------------------------------
Begin
  NP1:=NbPos(N)-P;
  extr_G := N Div puissance(10, NP1);
End; //Extr_G