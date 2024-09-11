Program EXO_9_Skeletal_Mul ;
Var
  i , j , A , B , P : Longint ;
Begin
  Writeln('Ce programme calcule les nombres remplacés par des étoiles : ');
  Writeln('----------------------------------------------');
  Writeln('| i         | j         | Résultat  |');
  Writeln('----------------------------------------------');
  For i := 14000 To 94999 Do
    Begin
      A := (i Div 1000) Mod 10 ;
      If A = 4 Then
        Begin
          For j := 509 To 599 Do
            Begin
              B := j Mod 10 ;
              If B = 9 Then
                Begin
                  P := i * j ;
                  If (P Mod 1000 = 392 ) And (P Div 1000000 = 7) Then
                    Begin
                      Write('| ', i:10, ' | ', j:10, ' | ', P:10, ' |');
                      Writeln;
                      Writeln('----------------------------------------------');
                    End;
                End;
            End;
        End;
    End;
  Readln;
End.
