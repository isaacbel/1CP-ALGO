Function NbPos(N:Longint): Integer;
//calcule le nombre de positions de N
Var
  Np: Integer;
Begin
  Np := 0; //initialisation
  While (N <> 0) Do
    Begin
      N := (N Div 10);
      Np := Np+1;
    End;
  NbPos := Np;
  //nombre de positions d''un nombre entier
End; //Fin Nb_Pos