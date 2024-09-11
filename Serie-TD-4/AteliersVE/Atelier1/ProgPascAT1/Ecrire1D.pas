Procedure Ecrire1D (T:Tab1D; Tai:Tind) ;
//Affichage de tableaux 1D
Var
  i: integer;
Begin
  For i:= 1 To Tai Do
    Write (T[i]:7, '|') ;
  Writeln;
End; //Fin Ecrire1D