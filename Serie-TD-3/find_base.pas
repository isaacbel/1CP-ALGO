Program EMD_1996 ;
//-------------------------- functions
Uses IsaacLibr;
Function est_grand(N : Longint): Integer;
// doner le plus grand chifre dans le nombre
Var
  D,k,B : Longint;
Begin
  D := N ;
  K := 1 ;
  While D > 0 Do
    Begin
      B := D Mod 10 ;
      If B > K Then
        K := B ;
      D := D Div 10 ;
    End;
  est_grand := K ;
End;
//------------------------------------

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
//---------------------------------------------------

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
Var
  trouve,R : Boolean;
  N,N2,sauvN, sauvN2,B1,base ,N_bigger ,L,O ,A: Longint;
  Chiffre : String;
Begin
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
        Writeln('enter the number N in the base B1 :');
        Readln(Chiffre);
      End;
    R := test_inferieur(N,B1);
    If R = False Then Writeln('enter again the inputs ');
  Until (R = True);
  sauvN := N ;
  If B1 < 10 Then
    Begin
      sauvN := B1_B2(N,B1,10);
    End
  Else
    sauvN := base16_to_base(Chiffre,10);
  Writeln('enter the number N2  :');
  Readln(N2);
  N_bigger := est_grand(N2);
  trouve := False ;
  L := 1;
  O := 0 ;
  base := N_bigger + 1;
  While Not trouve Do
    Begin
      sauvN2 := N2 ;
      While sauvN2 <> 0 Do
        Begin
          A := sauvN2 Mod 10 ;
          sauvN2 := sauvN2 Div 10 ;
          O := O + A*L ;
          L := L*base ;
        End;
      If O = sauvN Then
        trouve := True
      Else base := base + 1;
    End;
  Writeln(' the base of ',N2,' is ',base );
  Readln;
End.