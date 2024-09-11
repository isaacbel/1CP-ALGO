Program EXO_1990 ;
Var
  i , NB , G_div , P_div : Integer;
  B : Boolean;
Begin
  Writeln('entre le nombre Nb : ');
  Readln(NB);
  G_div := 1 ;
  P_div := NB;
  B := True;
  i := 1;
  While (i <= (NB Div 2)) And B Do
    Begin
      i := i +1 ;
      If ( NB Mod i = 0 ) Then
        Begin
          P_div := i;
          G_div := NB Div i ;
          B := False;
        End;
      
    End;
  If ( P_div = NB) Then
    Writeln('le nombre ',Nb , ' pas de diviseur')
  Else If ( P_div = G_div) Then
         Writeln('le nombre ', NB , ' a un seul diviseur est :  ', i)
  Else
    Writeln('le plus petir diviseur est :  ', P_div, ' et le plus grand diviseur est : ',G_div);
  Readln;
End.