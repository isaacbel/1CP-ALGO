Program Tri_comptage_2;

Const Max = 1000;
  MaxL = 100;
  MaxC = 100;
Type
  Tind = 1..Max ;
  TindL = 1..MaxL;
  TindC = 1..MaxC ;
  TABD1 = Array[Tind] Of Integer;
  TabD2 = Array[TindL,TindC] Of Integer;
  //--------------------------------------------

Procedure Ecrire1D(T:TABD1 ; Tai:Tind);
Var
  i: Integer;
Begin
  For i :=1 To Tai Do
    Begin
      Write(T[i],'|') ;
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
//------------------------------------------------

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
//----------------------------------------------

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
//-----------------
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
//---------------------------------------------------------------------
Var
  T,Tab3 : TABD1 ;
  Tai: Tind ;
Begin
  WriteLn('Tri par comptage par deux tableaux : ');
  LecRand (T,Tai);
  Ecrire1D(T , Tai);
  Tri_Comptage2(T,Tai);
  Readln;
End.
