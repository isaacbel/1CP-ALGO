Program Som_B1_B2 ;
Uses Crt;
//-------------------------------

Function Som_base(N1,N2,base : Longint): Longint;
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
      If c >= base Then
        Begin
          S := S + (c - base)*p ;
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
  Som_base := S ;
End;
//---------------------------

Function test_inferieur(N,J : Longint): Boolean;
Var
  B ,A : Longint;
  K : Boolean;
Begin
  B := N;
  K := True;
  While (B > 0) And ( K) Do
    Begin
      A := B Mod 10 ;
      If A >= J Then
        K := False;
      B := B Div 10 ;
    End;
  test_inferieur := K
End;
//-----------------------------------------
Var
  N1,N2,B,som : Longint;
  R1,R2 : Boolean;
  userInput : Char;
Begin
  Repeat
    Writeln('enter the base B');
    Readln(B);
    Writeln('enter the number N1 and N2  in the base ',B );
    Readln(N1);
    Readln(N2);
    R1 := test_inferieur(N1,B);
    R2 := test_inferieur(N2,B);
    If (R1 = True) And (R2= True) Then
      Begin
        som := Som_base(N1,N2,B);
        Writeln(som);
      End
    Else
      Begin
        Writeln('The number is not in the base you inter. Please enter another number.');
        // Consume the newline character left in the input buffer
      End;
    Writeln('Do you want to check another number? (Y/N)');
    Readln(userInput);
  Until (Upcase(userInput) <> 'Y');
  Readln;
End.
