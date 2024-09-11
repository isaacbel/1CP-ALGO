Program Equation_2_degre ;
Var
  X1, X2, X, Delta, A, B, C: Real ;
Begin
  Repeat
    Writeln('enter A :');
    Readln(A);
    If A = 0 Then
      Begin
        Writeln('enter un nombre pas nul ');
      End;
  Until (A > 0);
  Writeln('enter B :');
  Readln(B);
  Writeln('enter C :');
  Readln(C);
  Delta := B*B - 4*A*C ;
  If Delta > 0 Then
    Begin
      X1 := (-B + Sqrt(Delta)) / (2*A);
      X2 := (-B - Sqrt(Delta)) / (2*A);
      Writeln('Two real roots: ', X1:6:2, ' and ', X2:6:2);
    End
  Else If Delta = 0 Then
         Begin
           X := -B / (2*A);
           Writeln('One real root: ', X:6:2);
         End
  Else
    Writeln('No real solution');
  Readln;
End.