Program Binair;
Uses Crt ;
Var
  Num, P, D, M, S, L, J, O, A, N,E, dayNumber,digit: Longint;
  repeatInput,userInput: Char;
  isBinary : Boolean;
Begin
  Repeat
	  Writeln('1 : decimale --> binaire');
		Writeln('2 : binaire --> dicimale')   ;
    Write('Enter a number (1-2): ');
    Readln(dayNumber);
    Case dayNumber Of
      1:
         Begin
           Writeln('Enter the dicimal number  : ');
           Readln(Num);
           P := 1;
           S := 0;
           While Num > 0 Do
             Begin
               M := Num Mod 2;
               Num := Num Div 2 ;
               S := S + M*P ;
               P := P*10;
             End;
           Writeln('The binary number is : ', S );
         End;
      2:
         Begin
           Repeat
             Writeln('Enter the bainary number  : ');
             Readln(N);
             D := N ;
             isBinary := True;
             While D > 0 Do
               Begin                         // tester si le nombre enter est un nombre binaire
                 digit := D Mod 10;
                 If (digit <> 0) And (digit <> 1) Then
                   Begin
                     isBinary := False;
                     break;
                   End;
                 D := D Div 10;
               End;
             If isBinary Then
               Begin
                 Writeln('The number is binary.') ;
                 L := 1;
                 O := 0;
                 While N <> 0 Do
                   Begin
                     A := N Mod 10 ;
                     N := N Div 10 ;
                     O := O + A*L ;
                     L := L*2 ;
                   End;
                 Writeln('The dicimal number is : ', O );
               End
             Else
               Begin
                 Writeln('The number is not binary. Please enter another number.');
                 // Consume the newline character left in the input buffer
               End;
             Writeln('Do you want to check another number? (Y/N)');
             Readln(userInput);
           Until (Upcase(userInput) <> 'Y');
         End;
      Else
        Writeln('Invalid input. Please enter 1 or 2.');
    End;
    Write('Do you want to repeat the code? (Y/N): ');
    Readln(repeatInput);
    Clrscr;
  Until (Upcase(repeatInput) <> 'Y');
  Readln;
End.
