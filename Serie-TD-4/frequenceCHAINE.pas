Program Frequence_chaine ;
Uses Crt;
//----------------------------------------------
Function cpt_chaine( Ph : String ;S_chaine : String) : Longint;
Var
  cpt ,i,K,L,L2 : Longint;
  trouve : Boolean;
Begin
  L := Length(Ph);
  L2 := Length(S_chaine);
  i := 1;
  cpt := 0;
  trouve := True;
  While (i < L ) Or trouve = True Do
    Begin
      K := Pos(S_chaine,Ph);
      If K <> 0 Then
        Begin
          cpt := cpt + 1;
        End
      Else trouve := False;
      Delete(Ph,i,K+L2-1);
      i := K+L2 ;
      L := L - i ;
      i := 1 ;
    End;
  cpt_chaine := cpt;
End;
//-------------------------------------------
Function cpt_chaine2( Ph : String ;S_chaine : String) : Longint;
Var
  K,i,cpt : Longint;
  ch : String;
Begin
  cpt := 0;
  K := Length(S_chaine);
  Writeln(K);
  For i:= 1 To Length(Ph)-K+1 Do
    Begin
      ch := Copy(Ph,i,K);
      If (ch = S_chaine) and ((ph[i+k]=' ')or (Pos(ph[i+k],Ph)=Length(ph))) and ((ph[i]=S_chaine[1]) or (ph[i-1]=' ') ) Then
        Begin
          cpt := cpt + 1;
        End;
    End;
  cpt_chaine2 := cpt ;
End;
//-------------------------------------------
Var
  Ph, S_chaine,Ch1,Ch2 : String;
  cpt,i,j : Longint;
Begin
  Writeln('calcule de la frequence d''une sous chaine de character : ');
  Writeln('enter la frase ');
  Readln(Ph);
  Writeln('entrer la sous chaine : ');
  Readln(S_chaine);
  For i:=1 To Length(Ph) Do
    Begin
      Ch1 := ch1 + Upcase(Ph[i]);
    End;
  For j:=1 To Length(S_chaine) Do
    Begin
      Ch2 := ch2 + Upcase(S_chaine[j]);
    End;
  cpt := cpt_chaine2(Ch1 ,Ch2);
  If cpt = 0 Then
    Writeln('la sous chaine n''est dans la phrase ')
  Else Writeln('la sous chaine est repete : ',cpt,'  fois ');
  Readln;
End.