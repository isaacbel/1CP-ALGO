Program CubicNumbers; // Exercise 1, Series 2
Var
  A, B, D, E, F, D_3, E_3, F_3, Sum: Integer;
Begin
  Writeln('Cubic numbers between 100 and 500:');
  WriteLn;
  For A := 100 To 500 Do
    Begin
      D := A Div 100;        // to get the first digit
      E := (A Mod 100) Div 10; // to get the second digit
      F := A Mod 10; // to get the last digit
      D_3 := D * D * D;
      E_3 := E * E * E;
      F_3 := F * F * F;
      Sum := D_3 + E_3 + F_3;
      If Sum = A Then
        Begin
          Writeln('The numbers are: ', D, ' ', E, ' ', F, ' = ', A);
          Writeln('--------------------------------------------');
          Writeln;
        End;
    End;
  Readln;
End.
