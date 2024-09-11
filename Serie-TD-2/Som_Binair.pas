Program Som_Binair ;
Var
  N1 , N2 , S , r , p , A , B , c,D1,D2,digit1,digit2 : Integer;
  isBinary : Boolean;
  userInput: Char;
Begin
  Repeat
    Writeln('enter le premier nombre bimair : ');
    Readln(N1);
    Writeln('enter le deusieme nombre bimair : ');
    Readln(N2);
    r := 0;
    p := 1;
    D1 := N1 ;
    D2 := N2;
    isBinary := True;
    While (D1 > 0) And (D2 > 0) Do
      // this loop test if the two numbers we enter are binary
      Begin
        digit1 := D1 Mod 10;
        digit2 := D2 Mod 10;
        If (digit1 <> 0) And (digit1 <> 1) And (digit2 <>0) And (digit2 <> 1) Then
          Begin
            isBinary := False;
            break;
          End;
        D1 := D1 Div 10;
        D2 := D2 Div 10 ;
      End;
    If isBinary Then
      Begin
        While (N1 > 0) Or (N2 > 0) Or( r > 0 ) Do
          // this loop do the addition
          Begin
            A := N1 Mod 10 ;
            B := N2 Mod 10 ;
            c := A + B + r ;
            If c >= 2 Then
              Begin
                S := S + (c - 2)*p ;
                r := 1;
              End
            Else
              Begin
                S := S + c*p ;
                r := 0 ;
              End;
            N1 := N1 Div 10 ;
            N2 := N2 Div 10 ;
            p := p*10;
          End;
        Writeln('la somme est : ',S);
      End
    Else
      Writeln('The numbers are  not binary. Please enter another numbers.');
    Writeln('Do you want to check another number? (Y/N)');
    Readln(userInput);
  Until (Upcase(userInput) <> 'Y');
  Readln;
End.
