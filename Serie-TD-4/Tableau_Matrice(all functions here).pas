Program TAB1D;
Const Max = 1000;
  MaxL = 100;
  MaxC = 100;
Type
  Tind = 1..Max ;
  TindL = 1..MaxL;
  TindC = 1..MaxC ;
  TABD1 = Array[Tind] Of Integer;
  TabD2 = Array[TindL,TindC] Of Integer;
  //------------------------------------------------
Procedure LirTab1D(Var T:TABD1 ; Var Tai :Tind);
Var
  i : Integer;
Begin
  Writeln('Donner la taille du tableau : ');
  Readln(Tai);
  Writeln('Donner les valeurs du tableau : ');
  For i:=1 To Tai Do
    Begin
      Write('T[ ',i,' ]');
      Readln(T[i]);
    End;
End;
//--------------------------------------------------

Procedure Ecrire1D(T:TABD1 ; Tai:Tind);
Var
  i: Integer;
Begin
  For i :=1 To Tai Do
    Begin
      Write(T[i],'|') ;
      Writeln;
    End;
End;
//-------------------------------------------------

Procedure LecRand (Var T :TABD1 ; Var Tai : Tind);
Var
  minI,maxI,i : Integer;
Begin
  Writeln('Donner la taille du tableau : ');
  Readln(Tai);
  Writeln('Iintervale [minI, maxI]des valeurs à prendre aléatoirement');
  Writeln('---------------------------------------------------------');
  Write('Donner la borne inférieure : ');
  Readln(minI);
  Write('Donner a borne supérieure : ');
  Readln(maxI);
  Randomize;
  For i:= 1 To Tai Do
    Begin
      T[i] := minI + Random((maxI - minI) + 1) ;
    End;
End;
//----------------------------------------------------------------

Function NbeV(T: TABD1 ; Tai : Tind ; V : Integer) : Integer;
Var
  i,cpt : Integer;
Begin
  cpt := 0;
  For i := 1 To Tai Do
    Begin
      If T[i] = V Then
        cpt := cpt + 1 ;
    End;
  NbeV := cpt ;
End;
//--------------------------------------------------------

Function minTab1D(T :TABD1 ; Tai : Tind ): Longint;
Var
  i : Integer;
  min : Longint;
Begin
  min := T[1] ;
  For i:=1 To Tai Do
    Begin
      If min > T[i] Then
        min := T[i];
    End;
  minTab1D := min;
End;
//------------------------------------------------------------
Function maxTab1D(T :TABD1 ; Tai : Tind ): Longint;
Var
  i : Integer;
  max : Longint;
Begin
  max := T[1] ;
  For i:=1 To Tai Do
    Begin
      If max < T[i] Then
        max := T[i];
    End;
  maxTab1D := max;
End;
//-----------------------------------------------------------

Procedure Tribulle1(Var T:TabD1 ; Tai : Tind);
Var
  j,i,tmp : Integer;
Begin
  For i:=Tai-1 Downto 1 Do
    Begin
      For j:=1 To i Do
        Begin
          If T[j] > T[j+1] Then
            Begin
              tmp := T[j+1];
              T[j+1] := T[j];
              T[j] := tmp;
            End;
        End;
    End;
End;
//---------------------------------------------

Procedure Tribulle2(Var T:TabD1 ; Tai : Tind);
Var
  i,j,tmp : Integer;
Begin
  For i:=1 To Tai-1 Do
    Begin
      For j:=1 To Tai -i Do
        Begin
          If T[j] > T[j+1] Then
            Begin
              tmp := T[j+1];
              T[j+1] := T[j];
              T[j] := tmp;
            End;
        End;
    End
End;
//------------------------------------
Procedure Tribulle3(Var T:TabD1 ; Tai : Tind);
Var
  i,tmp,j : Integer;
  permuter : Boolean;
Begin
  Repeat
    permuter := False;
    For i:=1 To Tai-1 Do
      Begin
        If T[i] > T[i+1] Then
          Begin
            tmp := T[i+1];
            T[i+1] := T[i];
            T[i] := tmp;
            permuter := True;
          End;
      End;
  Until permuter = False;
End;
//----------------------------------------------

Procedure Tri_Insertion(Var T:TabD1 ; Tai : Tind);
Var
  i,j,tmp : Integer;
Begin
  For i:=2 To Tai Do
    Begin
      tmp := T[i];
      j := i-1 ;
      While (T[j] > tmp ) And (j >= 1) Do
        Begin
          T[j+1] := T[j];
          j := j-1;
        End;
      T[j+1] := tmp;
    End;
End;
//--------------------------------------------------

Procedure PERMUT (Var A, B: Longint);
//permute les contenus de A et B
Var
  Tmp: Longint;
Begin
  Tmp := A;
  A := B;
  B := Tmp;
End;
//fin Permut
//---------------------------------------------------------

Function indDuMin (T: TabD1; B1, B2: Tind): Integer;
//donne l'indice du plus petit élément dans une portion du tableau
Var
  Ind, i: Integer;
Begin
  Ind := B1;
  For i := (B1+1) To B2 Do
    Begin
      If T[i] < T[Ind] Then Ind := i;
    End;
  indDuMin := Ind;
End;
//fin IndDuMin
//----------------------------------------------------

Procedure TRSEL (Var T : TABD1; Tai: Tind);
//trie les éléments de T par ordre croissant
Var
  i, Indice : Integer;
Begin
  //TRISEL
  For i := 1 To (Tai -1) Do
    Begin
      Indice := IndDuMin (T, i, Tai);
      PERMUT (T[i], T[Indice]);
    End;
End;
//fin TRISEL
//------------------------------------------------

Procedure Tri_Trnasposition(Var T:TABD1; Tai: Tind);
Var
  i,j : Integer;
Begin
  For i:=1 To Tai-1 Do
    Begin
      If T[i] > T[i+1] Then
        Begin
          PERMUT (T[i], T[i+1]);
          j := i;
          Repeat
            If T[j] < T[j-1] Then
              PERMUT (T[j], T[j-1]);
            j := j-1;
          Until j=1 ;
        End;
    End;
End;
//------------------------------------------------
//------------------------------------------------

Procedure Ord_pair(Var T:TABD1; Tai: Tind);
Var
  i,j : Integer;
Begin
  TRSEL (T, Tai);
  For i:=1 To Tai-1 Do
    Begin
      For j:=1 To Tai-1 Do
        Begin
          If (T[j] Mod 2 <> 0)And(T[j+1] Mod 2 = 0) Then
            PERMUT (T[j], T[j+1]);
        End;
    End;
End;
//------------------------------------------------

Function RechDichV(T:TabD1 ; Tai: Tind ; V : Longint): Boolean;
Var
  Min,Max,mil : Integer;
  trouv : Boolean;
Begin
  Trouv := False;
  Min := 1;
  Max := Tai;
  While (Min < Max) Do
    Begin
      mil := (Max + Min) Div 2 ;
      If T[mil] < V Then
        Min := mil + 1
      Else Max := mil;
      If T[mil] = V Then
        Trouv := True;
    End;
  RechDichV := Trouv;
End;
//---------------------------------------------
// Matrice

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
      For j:=1 To NbL Do
        Begin
          Write('T[',i,',',j,']');
          Read(T[i,j]);
        End;
    End;
End;
//--------------------------------------------

Procedure Ecrire2D( T:TABD2 ; NbL: TindL; NbC: TindC) ;
Var
  i,j : Integer;
Begin
  For i:=1 To NbL Do
    Begin
      For j:=1 To NbL Do
        Begin
          Write(T[i,j],' |');
        End;
      Writeln;
    End;
End;
//--------------------------------------------------

Procedure LecRandD2 (Var T :TABD2 ;Var NbL: TindL; Var NbC: TindC);
Var
  minI,maxI,i ,j: Integer;
Begin
  Writeln ('‘Donner le Nb de lignes du tableau ‘');
  Read(NbL);
  Writeln(' ‘Donner le Nb de colonnes du tableau ‘') ;
  Read (NbC);
  Writeln('Iintervale [minI, maxI]des valeurs à prendre aléatoirement');
  Writeln('---------------------------------------------------------');
  Write('Donner la borne inférieure : ');
  Readln(minI);
  Write('Donner a borne supérieure : ');
  Readln(maxI);
  Randomize;
  For i:= 1 To NbL Do
    Begin
      For j:=1 To NbC Do
        Begin
          T[i,j] := minI + Random((maxI - minI) + 1) ;
        End;
    End;
End;
//--------------------------------------------------
Procedure SomCol(T:TABD2 ; NbL:TindL;NbC :TindC;Var T2:TABD1);
Var
  cpt ,i ,j : Integer;
Begin
  For j:= 1 To NbC Do
    Begin
      cpt := 0;
      For i:=1 To NbL Do
        Begin
          cpt := cpt + T[i,j] ;
        End;
      T2[j] := cpt;
    End;
End;
//----------------------------------------------------

Procedure Tradui_Matrice_Tableau(T:TABD2 ; NbL:TindL;NbC :TindC;Var T2:TABD1;Var K:Tind);
Var
  i,j : Integer;
Begin
  K := 1;
  For i:=1 To NbL Do
    Begin
      For j:=1 To NbC Do
        Begin
          T2[K] := T[i,j];
          K := K + 1;
        End;
    End;
End;
//-------------------------------------------
Function compt_inf(T : TABD1 ; Tai:Tind ; V : Integer): Integer;
// caculer combient de nombre est inferieur a la valeur V
Var
  cpt,i : Integer;
Begin
  cpt := 0;
  For i:=1 To Tai Do
    Begin
      If ( T[i] < V ) Then cpt := cpt + 1 ;
    End;
  compt_inf := cpt ;
End;
Procedure inf_val_tab ( T : TABD1; Tai : Tind ; Var TiV : TABD1);
// cette procedure pour chaque élément on compte le nombre
//d'éléments qui lui sont inférieurs et on range le résultat trouvé
Var
  i : Integer;
Begin
  For i:=1 To Tai Do
    Begin
      TiV[i] := compt_inf(T,Tai,T[i]) ;
    End;
End;
Procedure Corrige_TiV(T : TABD1 ; Tai : Tind ;Var TiV : TABD1 );
Var
  i,j : Integer;
Begin
  For i:=1 To Tai Do
    Begin
      For j:=1 To Tai Do
        Begin
          If (TiV[i] = TiV[j] ) And ( j <> i ) Then TiV[j] := TiV[j] + 1 ;
        End;
    End;
End;
Procedure Tri_Comptage3(T : TABD1; Tai: Tind ; Var Tab3 : TABD1 );
Var
  i : Integer;
  TiV : TABD1;
Begin
  inf_val_tab(T,Tai,TiV);
  Writeln('');
  Writeln('voici la table de comptage avant correction');
  Ecrire1D(TiV , Tai);
  Corrige_TiV(T,Tai,TiV);
  Writeln('');
  Writeln('voici la table de comptage apres la correction ');
  Ecrire1D(TiV , Tai);
  For i:=1 To Tai Do
    Begin
      Tab3[TiV[i] + 1] := T[i];
    End;
  Writeln('');
  Writeln('le nouveau tableau :');
  Ecrire1D(Tab3 , Tai);
End;
//----------------------------------------------------------

Procedure Tri_Comptage2(Var T : TABD1; Tai: Tind );
Var
  i , j: Integer;
  TiV : TABD1;
Begin
  inf_val_tab(T,Tai,TiV);
  Writeln('');
  Writeln('voici la table de comptage avant correction');
  Ecrire1D(TiV , Tai);
  Corrige_TiV(T,Tai,TiV);
  Writeln('');
  Writeln('voici la table de comptage apres la correction ');
  Ecrire1D(TiV , Tai);
  For j:=0 To Tai -1 Do
    Begin
      For i:=1 To Tai Do
        Begin
          If (TiV[i] = j) And (j <> i-1 ) Then
            Begin
              PERMUT (T[i], T[j+1]);
              PERMUT (TiV[i], TiV[j+1]);
            End;
        End;
    End;
  Writeln('');
  Writeln('le nouveau tableau :');
  Ecrire1D(T,Tai);
End;
//-------------------------------------------

Procedure Tri_comptage1(Var T : TABD1 ; Tai : Tind );
Var
  i,j : Integer;
Begin
  For i:= 1 To Tai Do
    Begin
      For j:=1 To Tai Do
        Begin
          If (i-1 <> compt_inf(T,Tai,T[i])) And (compt_inf(T,Tai,T[j])=i-1)Then
            Begin
              PERMUT (T[i], T[j]);
            End;
        End;
    End;
End;
Begin
End.
