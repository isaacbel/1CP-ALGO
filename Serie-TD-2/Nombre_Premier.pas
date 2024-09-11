Program PrimeNumber;                                  // exo 2 serie 2
Uses crt;
Var
  I1, I2, i: Integer;
  isPrime: Boolean;
Begin
  Clrscr; // Clear the screen
  Gotoxy(10, 5); // Set cursor position to column 10, row 5
  Write('Hello, world!'); // Display a message
  Readln; // Wait for user input before exiting

  Writeln('Enter the bounds of the interval: ');
  Readln(I1, I2);

  // First method to find prime numbers
  For I1 := I1 To I2 Do
    Begin
      isPrime := True;
      For i := 2 To I1 Div 2 Do
        Begin
          If I1 Mod i = 0 Then
            Begin
              isPrime := False;
              Break;
            End;
        End;
      If isPrime And (I1 > 1) Then
        Begin
          Writeln('The number is prime: ', I1);
        End;
    End;

  // Second method to find prime numbers using a While loop
  For I1 := I1 To I2 Do
    Begin
      isPrime := True;
      i := 2;
      While (i <= (I1 Div 2)) And isPrime Do
        Begin
          If I1 Mod i = 0 Then
            Begin
              isPrime := False;
            End;
          i := i + 1;
        End;
      If isPrime And (I1 > 1) Then
        Begin
          Writeln('The number is prime: ', I1);
        End;
    End;

  Readln;
End.
