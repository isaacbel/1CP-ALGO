Program Exo_9_serie4 ;
Uses Crt,IsaacLibr;
//-------------------------------------
Procedure count_ch(Ph:String;Var K : Integer;Var ch :Char;d : Integer;Var seuil : Boolean);
Var
  cpt,i : Integer;
  C : Char;
Begin
  K := 1;
  cpt := 1 ;
  For i:=1 To Length(Ph)-1 Do
    Begin
      If Ph[i] = Ph[i+1] Then
        Begin
          cpt := cpt + 1;
          C := ph[i];
          If cpt > k Then
            Begin
              K := cpt ;
              ch := C;
            End;
        End
      Else cpt := 1;
    End;
  If k > d Then
    seuil := True
  Else seuil := False;
End;
//------------------------------------------------

Function creat_ch(ch:String; cpt: Integer): String;
Var
  i: Integer;
  creat : String;
Begin
  creat := '';
  For i := 1 To cpt Do
    Begin
      creat := creat + ch;
    End;
  creat_ch := creat;
End;
//---------------------------------------------
Procedure compresser(Var Ph : String;d:Integer; seuil : Boolean);
Var
  cpt, P: Integer;
  ch: Char;
  st, ch2,ch3: String;
Begin
  count_ch(Ph, cpt, ch,d,seuil);
  st := creat_ch(ch, cpt);
  P := Pos(st, Ph);
  Delete(Ph, P, cpt-1);
  Str(cpt,ch3);
  If seuil = True Then
    ch2 := '[' + ch3+ ']'
  Else
    ch2 := '[[' + ch3+ ']';
  // Convert Integer to String
  Insert(ch2, Ph, P);
End;
//-------------------------------------------------

Procedure decompesser(Var Ph : String);
Var
  i,K,P,n,err,valeur,j: Integer;
  H : Char;
  ch2,ch3,ch : String;
Begin
  i := 1;
  valeur := 0;
  While (i<= Length(Ph)) Do
    Begin
      H := Ph[i] ;
      Val(H,n,err);
      If err = 0 Then
        Begin
          valeur := concate(valeur,n); ;
        End;
      i := i+1 ;
    End;
  For j:=1 To Length(Ph) Do
    Begin
      K := Ord( Ph[j]);
      If (K = Ord('[')) Or (K = Ord(']')) Then
        Begin
          Delete(Ph,j,1);
        End;
    End;
  Str(valeur,ch3);
  P := Pos(ch3,ph);
  Delete(Ph,P,Length(CH3));
  Ch := Copy(Ph,P,1);
  Ch2 := creat_ch(Ch, valeur-1);
  Insert(CH2,Ph,P);
End;
//-------------------------------------------------
Var
  ph : String;
  ch : Char;
  cpt,d : Integer;
  seuil : Boolean;
Begin
  Writeln('enter a String :');
  Readln(ph);
  Writeln('enter seul :');
  Readln(d);
  count_ch(Ph, cpt,ch,d,seuil);
  Writeln(cpt,'    ',Ch);
  compresser(Ph,d,seuil);
  Writeln;
  Writeln(ph);
  Writeln;
  decompesser(Ph);
  Writeln(Ph);
  Readln;
End.
