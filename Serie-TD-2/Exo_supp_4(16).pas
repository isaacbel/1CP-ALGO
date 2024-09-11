Program NombresDivisiblesWithoutBreak;
Var
  N1, N2, i, chiffre, nombre: Integer;
  divisibilityCheckPassed: Boolean;
Begin
  N1 := 200;
  N2 := 350;
  For i := N1 To N2 Do
    Begin
      nombre := i;
      divisibilityCheckPassed := True;
      While (nombre > 0) And divisibilityCheckPassed Do
        Begin
          chiffre := nombre Mod 10;
          If (chiffre <> 0) And (i Mod chiffre <> 0) Then
            divisibilityCheckPassed := False;
          nombre := nombre Div 10;
        End;
      If divisibilityCheckPassed Then
        Writeln(i,' ');
    End;
  Readln;
End.