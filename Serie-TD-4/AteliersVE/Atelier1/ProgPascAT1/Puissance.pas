Function Puissance(X,e:Integer): Longint;
//Calcul de X puissance e
Var
  i : Integer;
  ps : Longint;
Begin //Puissance
  ps := 1;   //initialisation
  For i:=1 To e Do
    ps := ps*X;
  Puissance := ps ;
  // On renvoie le résulat de X puissance e
End; //Fin Fonction Puissance