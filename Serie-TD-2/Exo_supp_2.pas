Program Exo_Supp_2;

Uses crt;

Var
  A, B, x, y, S, p, q: LongInt;
  strnum1, strnum2: String;

Begin
  Clrscr;

  // Loop to ensure the user inputs two four-digit numbers
  While True Do
    Begin
      Writeln('Enter the first number: ');
      Readln(A);
      Str(A, strnum1);

      Writeln('Enter the second number: ');
      Readln(B);
      Str(B, strnum2);

      // Check if both numbers are four digits long
      If (Length(strnum1) <> 4) Or (Length(strnum2) <> 4) Then
        Begin
          Writeln('Please enter a four-digit number.');
        End
      Else
        Break;
    End;

  // Initialize variables
  p := 1;
  q := 1;
  S := 0;

  // Combine the digits from A and B according to the given pattern
  While (A > 0) Or (B > 0) Do
    Begin
      x := A Mod 10; // Get the last digit of A
      y := B Mod 10; // Get the last digit of B
      S := S + (x * 10 * p + y * q); // Calculate the combined value
      A := A Div 10; // Remove the last digit from A
      B := B Div 10; // Remove the last digit from B
      p := p * 100; // Update multiplier for the next digit of A
      q := q * 100; // Update multiplier for the next digit of B
    End;

  Writeln('The number S is: ', S); // Output the result
  Readln;
End.
