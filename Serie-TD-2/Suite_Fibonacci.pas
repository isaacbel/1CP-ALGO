Program Suite_Fibonacci;
Uses Crt;
Var
  Fib0, Fib1, FibN, i, N: Integer;
  repeatInput: Char;
Begin
  Clrscr;
  Gotoxy(0, 5);
  Write('Bienvenue � notre programme, s''il vous pla�t, appuyez sur Entr�e ');
  Readln;
  Repeat
    Writeln;
    Writeln('Entrez la valeur de N (N > 1) pour calculer le Ni�me terme de la suite de Fibonacci:') ;
    
    Readln(N);
    If N < 1 Then
      Begin
        Writeln('Veuillez entrer un nombre plus grand que 1. ');
      End
    Else
      Begin
        Fib1 := 1;
        Fib0 := 0;
        If N = 1 Then
          Begin
            Writeln('Le premier nombre dans la suite de Fibonacci est : ', N);
          End
					
        Else
          Begin
            For i := 2 To N Do
              Begin
                FibN := Fib0 + Fib1 ;
                Fib0 := Fib1 ;
                Fib1 := FibN ;
              End;
            Writeln('Le Ni�me nombre de la suite de Fibonacci est : ', FibN);
          End;
      End;
    Write('Voulez-vous r�p�ter le programme ? (O/N) : ');
    Readln(repeatInput);
  Until (Upcase(repeatInput) <> 'O');
  Readln;
End.