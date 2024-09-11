Program EXO_10 ;
Var
  N , S , i , ordre ,D,k : Longint ;
Begin
  Writeln('Enter le nombre N : ');
  Readln(N);
  Writeln;
  Write('la sequance des nombre est : ',N , ' ');
  D := N ;
  S := 1;
  ordre := 0 ;
  While (N <> 1) And (D <> k) Do
    Begin
      For i:=2 To (N Div 2) Do
        Begin
          If (N Mod i = 0) Then
            S := S + i ;
        End;
      Write(S,' ');
      N := S;
      k := N ;
      S := 1 ;
      ordre := ordre + 1 ;
    End ;
  Writeln;
  If N = 1 Then
    Begin
      If ordre = 1 Then
        Writeln('Le nombre ', D ,' est un nombre premier ');
    End
  Else
    Begin
      If ordre = 1 Then
        Writeln('Le nombre ',N ,' est nombre social et parfait d''ordre 1 ')
      Else If ordre = 2 Then
             Writeln('le nombre  ',N,' est un nombre social et ami d''ordre 2')
      Else
        Writeln('le nombre  ',N,' est un nombre social d''ordre  ',ordre );
    End;
  Readln;
End.
