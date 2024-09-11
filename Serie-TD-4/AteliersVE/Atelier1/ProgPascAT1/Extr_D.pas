Function Extr_D (N, P:Longint): Longint;
// ------------------------------------------
// Extrait P positions a droite de N
// ------------------------------------------
Var NP1:Integer;
//-------------------------------
{$i puissance}
{$i NbPos}
//-------------------------------
Begin
  NP1:=NbPos(N)-P+1;
  extr_D := N Mod puissance(10,NP1);
End; //Extr_D