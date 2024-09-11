Program EXO_2015_2016 ;
Uses Crt,IsaacLibr;
//--------------------------------------------
Const Max = 1000;
  MaxL = 100;
  MaxC = 100;
Type
  Tind = 1..Max ;
  TindL = 1..MaxL;
  TindC = 1..MaxC ;
  TABD1 = Array[Tind] Of Integer;
  TabD2 = Array[TindL,TindC] Of Integer;
  //----------------------------------------------
Procedure Lect2D(Var T:TABD2 ;Var NbL: TindL; Var NbC: TindC) ;
Var
  i,j : Integer;
Begin
  Writeln ('‘Donner le Nb de lignes du tableau ‘');
  Read(NbL) ;
  Writeln(' ‘Donner le Nb de colonnes du tableau ‘');
  Read (NbC);
  For i:=1 To NbL Do
    Begin
      For j:=1 To Nbc Do
        Begin
          Write('T[',i,',',j,']');
          Read(T[i,j]);
        End;
    End;
End;
//--------------------------------------------
Procedure Ecrire2D(T: TABD2; NbL: TindL; NbC: TindC);
Var
  i, j: Integer;
Begin
  // Affichage des numéros de colonnes
  Write('    ');
  // Espace pour aligner avec les valeurs de la matrice
  For j := 1 To NbC Do
    Write(j : 4);
  Writeln;
  // Affichage de la ligne supérieure de la matrice
  Write('  +');
  For j := 1 To NbC - 1 Do
    Write('-----');
  Writeln('----+');
  // Affichage des lignes de la matrice avec les valeurs et les numéros de lignes
  For i := 1 To NbL Do
    Begin
      Write(i : 2, '¦ ');
      // Numéro de ligne suivi d'une barre verticale
      For j := 1 To NbC Do
        Write(T[i, j] : 3, ' ¦ ');
      // Valeur de la matrice suivie d'une barre verticale
      Writeln;
      // Affichage de la ligne de séparation entre les lignes de la matrice
      If i < NbL Then
        Begin
          Write('  +');
          For j := 1 To NbC - 1 Do
            Write('----+');
          Writeln('----¦');
        End;
    End;
  // Affichage de la ligne inférieure de la matrice
  Write('  +');
  For j := 1 To NbC - 1 Do
    Write('-----');
  Writeln('----+');
End;
//-------------------------------------------------
Function calcul_Produit(N:Longint): Longint;
Var
  i,S,A ,D: Integer;
Begin
  S := 1;
  D := N;
  For i:=1 To NBPOS(D) Do
    Begin
      A := D Mod 10;
      S := S*A ;
      D := D Div 10;
    End;
  calcul_Produit := S ;
End;
//-------------------------------------------------

Function est_exist(N,digit : Longint) : Boolean;
Var
  A : Integer;
  K : Boolean;
Begin
  K := False;
  Repeat
    A := N Mod 10 ;
    If A=digit Then
      K := True;
    N := N Div 10 ;
  Until (K=True) Or (N = 0);
  est_exist := K ;
End;
//----------------------------------------------------

Procedure Part1(N : Longint;Var N_rech : Integer;Var N_rech_cpt : Integer);
Var
  Q , C ,i,B,rech : Integer;
  K ,bool: Boolean;
Begin
  N_rech_cpt := 0;
  For i:=1 To N Do
    Begin
      rech := i ;
      C := 1;
      Repeat
        K := est_exist(rech,0);
        If K = False Then
          Begin
            B := rech + calcul_Produit(rech);
            rech := B ;
            c := c + 1;
          End;
      Until k = True;
      If C > N_rech_cpt Then
        Begin
          N_rech_cpt := C;
          N_rech := i;
        End;
    End;
End;
//-------------------------------------------------
Procedure Part2(N2,ficonditi : Longint;Var N_rech : Integer);
Var
  Q , C ,i,B,rech : Integer;
  K ,bool: Boolean;
Begin
  For i:=1 To N2 Do
    Begin
      rech := i ;
      C := 1;
      Repeat
        K := est_exist(rech,0);
        If K = False Then
          Begin
            B := rech + calcul_Produit(rech);
            rech := B ;
            c := c + 1;
          End;
      Until k = True;
      If C = ficonditi Then
        Begin
          N_rech := i;
          Write(N_rech,' |');
        End;
    End;
End;
//--------------------------------------------------
Procedure Part3(N2 : Longint;Var T : TabD2 ;Var j2:TindL;Var C :TindC);
Var
  Q ,i,B,rech,cpt,ct,N_rech : Integer;
  K ,bool: Boolean;
  j : Tindl;
Begin
  For j:=1 To N2 Do
    Begin
      ct := 0;
      For i:=1 To N2 Do
        Begin
          rech := i ;
          Cpt := 1;
          Repeat
            K := est_exist(rech,0);
            If K = False Then
              Begin
                B := rech + calcul_Produit(rech);
                rech := B ;
                cpt := cpt + 1;
              End;
          Until k = True;
          If (Cpt = j) And (k = True) Then
            Begin
              ct := ct+ 1 ;
              C := ct ;
              N_rech := i;
              T[j,C] := N_rech ;
              j2 := j;
            End;
        End;
    End;
End;
//--------------------------------------------------
//--------------------------------------------------
Var
  N ,N2,N_rech,N_rech2,N_rech_cpt,l,ficonditi : Integer;
  K : Boolean;
  T : TabD2 ;
  j2 : TindL;
  C : Tindc;
Begin
  Writeln('partie 1');
  Writeln('Donner');
  Readln(N);
  Part1(N , N_rech,N_rech_cpt);
  Writeln('nombre rechercher est : ',N_rech ,'fecomditi :   ',N_rech_cpt);
  Writeln('partie 2 ');
  Writeln('Donner N2');
  Readln(N2);
  Writeln('Doner ficonditi :');
  Readln(ficonditi);
  Part2(N2,ficonditi, N_rech2 ) ;
  Writeln;
  Writeln('-------------------------------------------');
  Part3(N2 , T , j2, C);
  Ecrire2D( T , j2, 4) ;
  Readln;
End.