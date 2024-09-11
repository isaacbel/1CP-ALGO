Program TD3 ;
Uses Wincrt,Crt;
//-------------------------------------- functions

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
//-------------------------------------------

Function B1_B2(N,B1,B2 : Longint): Longint;
Var
  L,O,A ,P,S ,M ,D : Longint;
Begin
  L := 1;
  O := 0;
  While N <> 0 Do
    Begin
      A := N Mod 10 ;
      N := N Div 10 ;
      O := O + A*L ;
      L := L*B1 ;
    End;
  D := O ;
  P := 1;
  S := 0;
  While D > 0 Do
    Begin
      M := D Mod B2;
      D := D Div B2 ;
      S := S + M*P ;
      P := P*10;
    End;
  B1_B2 := S ;
End;

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
//--------------------------------------------
Function ToHex(Number, B_initial,B : Longint): String;
Var
  remainder,L,Number2,A: Longint;
  hexResult: String;
Begin
  L := 1;
  Number2 := 0;
  While Number <> 0 Do
    Begin
      A := Number Mod 10 ;
      Number := Number Div 10 ;
      Number2 := Number2 + A*L ;
      L := L*B_initial ;
    End;
  hexResult := '';
  If Number2 = 0 Then
    hexResult := '0'
  Else
    Begin
      While Number2 > 0 Do
        Begin
          remainder := Number2 Mod B;
          If remainder < 10 Then
            hexResult := Char(Ord('0') + remainder) + hexResult
          Else
            hexResult := Char(Ord('A') + (remainder - 10)) + hexResult;
          Number2 := Number2 Div B;
        End;
    End;
  ToHex := hexResult;
End;
//--------------------------------------------
Function base16_to_base(N : String;B2:Integer): Longint;
Var
  L,K,P ,S,E,U,D,M: Longint;
  CH, ray: Char;
  err: Integer;
Begin
  L := Length(N);
  K := L;
  P := 1;
  S := 0;
  For K:=L Downto 1 Do
    Begin
      CH := N[K];
      If (CH >= 'A') And (CH <= 'F') Then
        E := Ord(CH) - Ord('A') + 10
      Else
        If (CH >='0')And (CH <= '9')Then
          Begin
            Val(CH,E,err);
          End;
      S := S + E * P;
      P := P * 16;
      ;
    End;
  D := S ;
  P := 1;
  U := 0;
  While D > 0 Do
    Begin
      M := D Mod B2;
      D := D Div B2 ;
      U := U + M*P ;
      P := P*10;
    End;
  base16_to_base := U;
End;
//--------------------------------------------

Procedure DisplayImage;
Begin
  Writeln('  _   _      _ _         __        __         _     _ _ ');
  Writeln(' | \ | | ___| | | ___    \ \      / /__  _ __| | __| | |');
  Writeln(' |  \| |/ _ \ | |/ _ \    \ \ /\ / / _ \|  __| |/ _` | |');
  Writeln(' | |\  |  __/ | | (_) |    \ V  V / (_) | |  | | (_| |_|');
  Writeln(' |_| \_|\___|_|_|\___( )    \_/\_/ \___/|_|  |_|\__,_(_) ');
  Writeln('                                                       ');
End;
//--------------------------------------------
Var
  B1,B2 ,New_numberB2,New_numberB1,N,N1,N2,B,som : Longint;
  ch : Integer;
  R,R1,R2 : Boolean;
  New_numberB ,chifre: String;
  userInput1,userInput2,userInput3: Char;
Begin
  Clrscr;
  Gotoxy(0, 10);
  DisplayImage ;
  Writeln('Bienvenue à notre programme, s''il vous plaît, appuyez sur Entrée ');
  Readln ;
  Writeln ;
  Repeat
    //Clrscr;
    Writeln ('------------------- MENU -------------------');
    Writeln('1 : Base1_To_Base2  ');
    Writeln('2 : Do the somme of two numbres in bases from 2 to 10 ');
    Writeln('3 : Quitter');
    Writeln;
    Readln(Ch);
    Writeln;
    Case Ch Of
      1:
         Begin
           TextColor(Red);
           // Set text color to Red
           Writeln('This code translate  a number from base 2 Until 16 and  from 16 until 2  ');
           Writeln;
           Writeln('Case 1 ');
           Repeat
             TextColor(White);
             Repeat
               R := True;
               Writeln('enter the base B1');
               Readln(B1);
               If B1 <= 10 Then
                 Begin
                   Writeln('enter the number N in the base B1 :');
                   Readln(N);
                 End
               Else
                 Begin
                   Writeln('enter the number N in the base : ',B1 );
                   Readln(chifre);
                 End;
               R := test_inferieur(N,B1);
               If R = False Then Writeln('enter again the inputs ');
             Until (R = True);
             Writeln('enter the base 2 (B2)');
             Readln(B2);
             If (B2 <= 10) And (B1 <= 10) Then
               Begin
                 New_numberB2 := B1_B2(N,B1,B2) ;
                 Writeln('the number ',N ,'in the base ',B2,' is  :' ,New_numberB2);
               End
             Else If B1 = 16 Then
                    Begin
                      New_numberB1 := base16_to_base(chifre,B2);
                      Writeln('the number ',chifre ,'in the base ',B2,' is  :' ,New_numberB1);
                    End
             Else
               Begin
                 New_numberB := ToHex(N,B1,B2);
                 Writeln('the number ',N ,'in the base ',B2,' is  : ',New_numberB);
               End;
             Writeln('Do you want to check another number? (Y/N)');
             Readln(userInput1);
           Until (Upcase(userInput1) <> 'Y');
         End;
      2 :
          Begin
            Repeat
              TextColor(White);
              Writeln;
              Writeln('Case 2 ');
              Writeln;
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
              Readln(userInput2);
            Until (Upcase(userInput2) <> 'Y');
          End;
      3:
         //Case4
         Begin
           Writeln;
           Writeln('Fin de programme');
         End
         Else Writeln('Erreur de choix')
    End;
    Writeln('Do you want to check another number? (Y/N)');
    Readln(userInput3);
  Until (Upcase(userInput3) <> 'Y');
  Readln;
End.