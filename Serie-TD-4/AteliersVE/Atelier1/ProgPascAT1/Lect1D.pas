Procedure Lect1D(Var T:Tab1D; Var Tai:Tind) ;
//Lecture de tableaux 1D
Var
  i: integer;
Begin
  Write('Taille du vecteur : ');
  Readln(Tai);
  Writeln('Donner les valeurs du tableau');
  Writeln('-----------------------------');
  For i := 1 To Tai Do
    Begin
      Write('T[',i,'] = ');
      Readln(T[i]) ;
    End ;
End ; //fin Lect1D