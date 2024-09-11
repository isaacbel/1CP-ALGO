
Unit IsaacLibr ;
Interface
//************************* Les fonctions ****************************
{1}
Function PUISS(x,y : Longint): Longint;
{2}
Function NBPOS(n : Longint): Longint;
{3}
Function FACTO(x : Integer): Longint;
{4}
Function NBPREM(n : Longint): Boolean;
{5}
Function NBPARF(N:Longint): Boolean;
{6}
Function Som_base(N1,N2,base : Longint): Longint;
{7}
Function B1_B2(N,B1,B2 : Longint): Longint;
{8}
Function test_inferieur(N,J : Longint): Boolean;
{9}
Function ToHex(Number, B_initial,B : Longint): String;
{10}

Function base16_to_base(N : String;B2:Integer): Longint ;
{11}
Function D_Circulair(N,K : Longint): Longint;
{12}
Function SOM_CH(n : Longint): Longint;
{13}
Function CROISSANT(N:Longint): Longint;
{14}
Function C_chiffre(n: Longint; chiffreRecherche: Integer): Longint;
// Counts occurrences of a specific digit in a number.
{15}
Function FindDigitPosition(number, digit: Integer): Integer;
//finds the position of a digit in a number
{16}
Function ChangeDigitAtPosition(num, U, newDigit: Longint): Longint;
//change a digit in a position with a new digit
{17}
Function GetDigit(number, position: Integer): Integer;
{18}

Procedure Suit_Aliquote(N : Integer; Var order:Integer;Var S : Integer);
 {19}
Function binaire_pure(Num : Integer): Integer;
{20}

Function C_Gray(N:Longint): Longint;
{21}

Function Module1(n:Longint): Longint;
{22}

Function Module2(n:Longint): Longint;
{23}

Function Friconce_N3(N : Longint): Boolean;
{24}
Function SOMDIV(N:Integer): Integer;
{25}

Function DECROISS(N:Longint): Longint;
{26}
Function permitation(n,P1,P2:Longint): Longint;
{27}
Function Chiffre_Different2(N1,N2 : Longint): Boolean;
{28}
Function est_grand(N : Longint): Integer;
// doner le plus grand chifre dans le nombre
{29}

Function est_supp_abond(N : Longint): Boolean;
{30}

Function ABOND(n:Longint): Boolean;
{31}
Function ExtrCh(B,p:Longint): Longint;
// Donne le chiffre se trouvant a la position p (gauche,Droite) de B
// retourne 0 en cas d'erreur
{32}
Function ExtCP(N,c,p: Longint): Longint;
{extrait c chiffres de N à partir de la position p}
{33}
Function SuppCH(N, ch: Longint): Longint;
{Donne le nombre N sans le chiffre ch}
{34}
Function Concate(a,b: Longint): Longint;

(***************************************************************************************************************)
Implementation
//{1}-----------------------------------------------------------------------------------------------
Function PUISS(x,y : Longint): Longint;
Var
  F,i: Longint;
Begin
  F := 1;
  For i:= 1 To y Do
    F := F*x;
  PUISS := F;
End;
//{2}-----------------------------------------------------------------------------------------------
Function NBPOS(n : Longint): Longint;
Var
  i: Longint;
Begin
  i := 0;
  While n <> 0 Do
    Begin
      i := i+1;
      n := n Div 10;
    End;
  NBPOS := i;
End;
//{3}-----------------------------------------------------------------------------------------------
Function FACTO(x : Integer): Longint;
Var
  F,i : Integer;
Begin
  If x=0 Then
    Begin
      FACTO := 1;
    End
  Else
    Begin
      F := 1;
      For i:=1 To x Do
        Begin
          F := F*i;
          FACTO := F;
        End;
    End;
End;

//{4}------------------------------------------------------------------------------------------------
Function NBPREM(n : Longint): Boolean;
Var
  i,r,nbdiv: Longint;
  k: Boolean;
Begin
  k := False;
  nbdiv := 0;
  For i:=2 To N Div 2 Do
    Begin
      If N Mod i = 0 Then
        nbdiv := nbdiv +1;
    End;
  If (nbdiv = 0) And( N>1) Then k := True
  Else k := False;
  NBPREM := k;
End;

//{5}------------------------------------------------------------------------------------------------
Function NBPARF(N:Longint): Boolean;
Var
  p,i : Longint;
  k: Boolean;
Begin
  p := 1 ;
  k := False;
  For i:=2 To (N Div 2) Do
    Begin
      If (N Mod i = 0) Then
        p := p + i ;
    End;
  If N=p Then k := True
  Else k := False;
  NBPARF := k;
End;
//{6}----------------------------------------------------------------------------
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
//{7}----------------------------------------------------------------------------

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
//{8}---------------------------------------------

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
//{9}--------------------------------------------

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
//{10}-------------------------------------------------------------------------

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
//{11}-------------------------------------------------------------

Function D_Circulair(N,K : Longint): Longint;
Var
  A,B,C,Num : Longint;
Begin
  A := NBPOS(N);
  B := N Div PUISS(10,A-K);
  C := N Mod PUISS(10,A-K);
  Num := C*PUISS(10,K) + B ;
  D_Circulair := Num ;
End;
//{12}------------------------------------------

Function SOM_CH(n : Longint): Longint;
// Function to calculate the sum of digits in a number
Var
  A , P,i : Integer;
Begin
  P := 0;
  For i:=1 To NBPOS(n) Do
    Begin
      A := n Mod 10 ;
      P := P + A ;
      n := n Div 10;
    End;
  SOM_CH := P ;
End;
//{13}---------------------------------------

Function CROISSANT(N:Longint): Longint;
Var
  croiss,sauvN: Longint;
  c: Integer;
Begin
  croiss := 0;
  For c:=1 To 9 Do
    Begin
      sauvN := N;
      While sauvN>0 Do
        Begin
          If sauvN Mod 10=c Then croiss := 10*croiss+c;
          sauvN := sauvN Div 10;
        End;
    End;
  CROISSANT := croiss;
End;
//{14}-------------------------------------------------------------

Function C_chiffre(n: Longint; chiffreRecherche: Integer): Longint;
// Counts occurrences of a specific digit in a number.
Var
  compteur, chiffre: Longint;
Begin
  compteur := 0;
  While n <> 0 Do
    Begin
      chiffre := n Mod 10;
      If chiffre = chiffreRecherche Then
        compteur := compteur + 1;
      n := n Div 10;
    End;
  C_chiffre := compteur;
End;
//{15}-----------------------------------------
Function FindDigitPosition(number, digit: Integer): Integer;
//finds the position of a digit in a number
Var
  position, currentDigit: Integer;
  digitFound: Boolean;
Begin
  position := 0;
  digitFound := False;
  While (number > 0) And (Not digitFound) Do
    Begin
      position := position + 1;
      currentDigit := number Mod 10;
      If currentDigit = digit Then
        digitFound := True
      Else
        number := number Div 10;
    End;
  If digitFound Then
    FindDigitPosition := position
  Else
    FindDigitPosition := 0;
  // Digit not found
End;
//{16}-----------------------------------------
Function ChangeDigitAtPosition(num, U, newDigit: Longint): Longint;
//change a digit in a position with a new digit
Var
  d,C,B ,A: Longint;
Begin
  A := (num Mod PUISS(10,U))Mod PUISS(10,U-1) ;
  B := (num Div PUISS(10,U))*PUISS(10,U) ;
  C := newDigit*PUISS(10,U-1);
  d := A + B + C ;
  ChangeDigitAtPosition := d ;
End;
//{17}-------------------------------------------------------
Function GetDigit(number, position: Integer): Integer;
Var
  digit: Integer;
Begin
  // Calculate the position of the digit from the right
  digit := (number Div PUISS(10, position - 1)) Mod 10;
  GetDigit := digit;
End;
//--------------------------------------------------------

Function SOMDIV(N:Integer): Integer;
Var
  i,som: Integer;
Begin
  som := 1;
  For i:=2 To (N Div 2) Do
    Begin
      If (N Mod i=0) Then
        Begin
          som := som +i;
        End;
    End;
  SOMDIV := som;
End;
//{18}--------------------------------------------------------

Procedure Suit_Aliquote(N : Integer; Var order:Integer;Var S : Integer);
Var
  D,k : Integer;
Begin
  Writeln('la sequance des nombre est : ',N , ' ');
  D := N ;
  order := 0 ;
  While (N <> 1) And (D <> k) Do
    Begin
      S := SOMDIV(N) ;
      Writeln(S,' ');
      N := S;
      k := N ;
      S := 0 ;
      order := order + 1 ;
    End ;
  If N = 1 Then
    Begin
      If order = 1 Then
        Writeln('Le nombre ', D ,' est un nombre premier ');
    End
  Else
    Begin
      If order = 1 Then
        Writeln('Le nombre ',N ,' est nombre social et parfait d''ordre 1 ')
      Else If order = 2 Then
             Writeln('le nombre  ',N,' est un nombre social et ami d''ordre 2')
      Else
        Writeln('le nombre  ',N,' est un nombre social d''ordre  ',order );
    End;
End;
//{23}--------------------------------------------------------------

Function Friconce_N3(N : Longint): Boolean;
Var
  D,A1,A2,A3 : Longint;
  K : Boolean;
Begin
  D := N ;
  A1 := D Mod 10;
  A2 := (D Mod 100) Div 10 ;
  A3 := D Div 100;
  If (A1 <> A2) And (A2 <> A3) And (A1 <> A3) And (A1 <> 0) And (A2 <> 0) And (A3 <> 0) Then
    K := True
  Else K := False ;
  Friconce_N3 := K ;
End;
//{20}-------------------------------------------------------
Function Module1(n:Longint): Longint;
// Performs a specific transformation on a number based on the position of the first digit '1'.
Var
  A , B , C : Longint;
Begin
  A := FindDigitPosition(n,1);
  B := GetDigit(n,A + 1);
  If B = 0 Then
    C := ChangeDigitAtPosition(n,A + 1,1)
  Else
    C := ChangeDigitAtPosition(n,A + 1,0) ;
  Module1 := C ;
End;
//{21}-----------------------------------------------------

Function Module2(n:Longint): Longint;
// Performs a transformation on a number depending on the last digit.
Var
  B,C : Longint;
Begin
  B := n Mod 10 ;
  If B = 0 Then
    C := ChangeDigitAtPosition(n,1,1)
  Else
    C := ChangeDigitAtPosition(n,1,0);
  Module2 := C ;
End;
//{19}----------------------------------------------------------

Function C_Gray(N:Longint): Longint;
Var
  A,B : Longint;
Begin
  A := C_chiffre(N,1) ;
  If (A Mod 2 = 0 ) Then
    B := Module2(N)
  Else
    B := Module1(N);
  C_Gray := B;
End;
//{22}..................................................................

Function binaire_pure(Num : Integer): Integer;
Var
  S , M , P : Integer;
Begin
  P := 1;
  S := 0;
  While Num > 0 Do
    Begin
      M := Num Mod 2;
      Num := Num Div 2 ;
      S := S + M*P ;
      P := P*10;
    End;
  binaire_pure := S ;
End;
//---------------------------------------------------------

Function DECROISS(N:Longint): Longint;
Var
  reord,x: Longint;
  i: Integer;
Begin
  reord := 0;
  For i:=9 Downto 0 Do
    Begin
      x := n;
      While x>0 Do
        Begin
          If x Mod 10=i Then reord := reord*10+i;
          x := x Div 10;
        End;
    End;
  DECROISS := reord;
End;
//---------------------------------------------------------
Function permitation(n,P1,P2:Longint): Longint;
Var
  A, B, D : Longint;
Begin
  A := (n Mod PUISS(10,P1)) Div PUISS(10,P1-1);
  B := (n Mod PUISS(10,P2)) Div PUISS(10,P2-1);
  D := n - (A *PUISS(10,P1-1) + B *PUISS(10,P2-1)) + A*PUISS(10,P2-1) + B*PUISS(10,P1-1) ;
  permitation := D ;
End;
//----------------------------------------------------------
Function Chiffre_Different2(N1,N2 : Longint): Boolean;
Var
  A1,A2,A3,B1,B2 : Integer;
  K : Boolean;
Begin
  A1 := N1 Mod 10;
  A2 := (N1 Mod 100) Div 10 ;
  A3 := N1 Div 100;
  B1 := N2 Mod 10 ;
  B2 := N2 Div 10 ;
  If (A1 <> A2) And (A2 <> A3) And (A1 <> A3) And (B1 <> B2) And (A1 <> B1) And (A1 <> B2) And
     (A2 <> B1) And (A2 <> B2) And (A3 <> B1) And (A3 <> B2) And (B1 <> B2) And (A1 <> 0) And (A2 <>
     0)
     And (A3 <> 0) And (B1 <> 0) And (B2 <> 0) Then
    K := True
  Else K := False ;
  Chiffre_Different2 := K ;
End;
//
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
//--------------------------------------------------------

Function ABOND(n:Longint): Boolean;
Var
  k : Boolean;
Begin
  k := False;
  If SOMDIV(n)>n Then
    k := True;
  ABOND := k;
End;
//--------------------------------------------------

Function est_supp_abond(N : Longint): Boolean;
// --------------------------------------------
// Donne VRAI si N est un nombre super abondant
// --------------------------------------------
Var
  i: Integer;
  tx,pretx: Real;
  res : Boolean;
Begin
  i := 1;
  res := True;
  If ABOND(N) Then
    Begin
      Tx := SOMDIV(N) / N ;
      Repeat
        If ABOND(i) Then
          Begin;
            preTx := SOMDIV(i) / i ;
            If preTx > tx Then res := False ;
          End;
        i := i+1;
      Until (i > N) Or (res = False);
      est_supp_abond := res;
    End
  Else est_supp_abond := False;
End;
//---------------------------------------------------
Function ExtrCh(B,p:Longint): Longint;
// ----------------------------------------------------------------------
// Donne le chiffre se trouvant a la position p (gauche,Droite) de B
// retourne 0 en cas d'erreur
// ----------------------------------------------------------------------
Begin
  If p <= NBPOS(B) Then
    ExtrCh := B Div PUISS(10,NBPOS(B)-p) Mod 10
  Else ExtrCh := 0;
End;
//Fin Fonction Extrch
//-----------------------------

Function ExtCP(N,c,p: Longint): Longint;
{extrait c chiffres de N à partir de la position p}
Var
  x: Longint;
Begin
  x := (N Div (PUISS (10,p-1)));
  x := (x-((x Div (PUISS (10,c))*(PUISS(10,c)))));
  extCP := x;
End;
//---------------------------
Function SuppCH(N, ch: Longint): Longint;
{Donne le nombre N sans le chiffre ch}
Var
  res, i ,p: Longint;
Begin
  res := 0;
  For i:=1 To NBPOS(N) Do
    Begin
      p := ExtCP(N,1,i);
      If p<>ch Then res := Concate(p,res);
    End;
  SuppCH := res;
End;
//---------------------------
Function Concate(a,b: Longint): Longint;
{ ex: a=12 b=53 concat(a,b)=1253}
Begin
  Concate := ((a*(PUISS (10,NBPOS(b))))+b);
End;
//---------------------------
//---------------------------------------------------------
End.
