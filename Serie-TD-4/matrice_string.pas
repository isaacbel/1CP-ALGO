Program EXO_53;
Uses Crt;
Const
  Max = 1000;
  MaxL = 100;
  MaxC = 100;
Type
  Tind = 1..Max;
  TindL = 1..MaxL;
  TindC = 1..MaxC;
  TABD1 = Array[Tind] Of String[10];
  TabD2 = Array[TindL, TindC] Of String[10];
  Matrice = Record
    Mat: TabD2;
    character: Char;
    bool: Boolean;
  End;
Procedure Lect2D(Var T: TABD2; Nbl: TindL; Nbc: TindC);
Var
  i, j: Integer;
Begin
  For i := 1 To Nbl Do
    Begin
      For j := 1 To Nbc Do
        Begin
          Write('T[', i, ',', j, ']');
          Readln(T[i, j]);
        End;
    End;
End;
Function cpt_char(mot: String; ch: Char): Integer;
Var
  i, L, cpt: Integer;
Begin
  cpt := 0;
  L := Length(mot);
  For i := 1 To L Do
    Begin
      If mot[i] = ch Then
        cpt := cpt + 1;
    End;
  cpt_char := cpt;
End;
Function Recher_char(T: TABD2; NbL: TindL; NbC: TindC; ch: Char): Integer;
Var
  cpt, i, K, j: Integer;
Begin
  cpt := 0;
  For i := 1 To NbL Do
    Begin
      For j := 1 To NbC Do
        Begin
          K := cpt_char(T[i, j], ch);
          If K <> 0 Then
            Begin
              cpt := cpt + K;
            End;
        End;
    End;
  Recher_char := cpt;
End;
//----------------------------------------
Procedure Ecrire2D(T: TABD2; NbL: TindL; NbC: TindC);
Var
  i, j: Integer;
Begin
  For i := 1 To NbL Do
    Begin
      For j := 1 To NbC Do
        Begin
          Write(T[i, j]:6, ' |');
        End;
      Writeln;
    End;
End;
Var
  T: Matrice;
  H: Integer;
Begin
  With T Do
    Begin
      Lect2D(Mat, 3, 3);
			Writeln('Entrer le caractere : ');
      Readln(character);
      H := Recher_char(Mat, 3, 3, character);
      If H <> 0 Then
        Begin
          Ecrire2D(Mat, 3, 3);
          bool := True;
          Writeln;
          Writeln(bool);
          Writeln('Ce caractere est repete : ', H, ' fois');
        End
      Else
        Begin
          Ecrire2D(Mat, 3, 3);
          bool := False;
          Writeln;
          Writeln(bool);
          Writeln('Ce caractere n''existe pas ');
        End;
    End;
End.