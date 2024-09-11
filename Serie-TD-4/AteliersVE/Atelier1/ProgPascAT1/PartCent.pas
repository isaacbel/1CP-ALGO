Function PartCent(N:Longint): Boolean;
// donne vrai si la partie centrale de N est composee du meme chiffre
Var
  nbext: Longint;
	NP1:Integer;
//-------------------------------
{$i extr_Nb}
{$i NbPos}
//-------------------------------
Begin //ParCent
  PartCent := False;
  If ((NbPos(N) Mod 2 = 0) And (NbPos(N)>2)) Then
    Begin
			NP1:= NbPos(N)Div 2;
      nbext := extr_Nb(N,2,NP1);
      If ((nbext = 0) Or (nbext Mod 11 =0)) Then PartCent := True
    End
  Else
    If NbPos(N)>3 Then
      Begin
			  NP1:=NbPos(N)Div 2;
        nbext := extr_Nb(N,3,NP1);
        If (nbext = 0) Or (nbext Mod 111 =0) Then PartCent := True;
      End;
End; //ParCent