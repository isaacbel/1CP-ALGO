Function extr_Nb(N,L,P:Longint) : Longint;
//------------------------------------------------------------------
// extrait de N un nombre de l chiffres a partir de la position P (incluse)
// les positions sont numerotees de  gauche a droite
//   si p est nul, negatif ou depassant la taille de N alors resultat=0
//   si l negatif resultat=0
//   si si l depasse la taille de N alors troncature a droite
//------------------------------------------------------------------
Var
  a: Longint;
//-------------------------------
{$i extr_D}
{$i extr_G}
{$i NbPos}
//-------------------------------
Begin
  If (P <= 0)Or (L<0) Or (P > NbPos(N)) Then EXTR_NB := 0
  Else
    Begin
      a := extr_G(N,P+L-1);
      extr_nb := extr_D(a,P);
    End;
End;// extr_Nb