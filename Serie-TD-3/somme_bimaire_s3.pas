Program exo5_S3 ;

Function Som_b(N1,N2 : Longint): Longint;
Var
  r,p,A,B,c,S : Longint;
Begin
  r := 0;
  p := 1;
  S := 0;
  While (N1 > 0) Or (N2 > 0) Or( r > 0 ) Do
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
  Som_b := S ;
End;
//---------------------------

Function is_binairy(N : Longint): Boolean;
Var
  Binary : Boolean;
  digit1,D1: Longint;
Begin
  D1 := N;
  Binary := True;
  While (D1 > 0) And Binary Do
    Begin
      digit1 := D1 Mod 10;
      If (digit1 <> 0) And (digit1 <> 1) Then
        Begin
          Binary := False;
        End;
      D1 := D1 Div 10;
    End;
  is_binairy := Binary;
End;
//---------------------------
Var
  N1,N2,som : Longint;
  userInput: Char;
  B1,B2 : Boolean;
Begin
  Repeat
    Writeln('Enter the two bainary numbers  : ');
    Readln(N1,N2);
    B1 := is_binairy(N1);
    B2 := is_binairy(N2);
    If (B1 = True) And (B2= True) Then
      Begin
        som := Som_b(N1,N2);
        Writeln(som);
      End
    Else
      Begin
        Writeln('The number is not binary. Please enter another number.');
        // Consume the newline character left in the input buffer
      End;
    Writeln('Do you want to check another number? (Y/N)');
    Readln(userInput);
  Until (Upcase(userInput) <> 'Y');
  Readln;
End.
