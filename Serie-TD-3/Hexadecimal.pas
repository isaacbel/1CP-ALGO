program DecimalToHexadecimalNoArray;

uses
  SysUtils,Crt;

function DecimalToHex(decimalNumber: LongInt): string;
var
  remainder: LongInt;
  hexResult: string;
begin
  hexResult := '';
  if decimalNumber = 0 then
    hexResult := '0'
  else
  begin
    while decimalNumber > 0 do
    begin
      remainder := decimalNumber mod 16;
      if remainder < 10 then
        hexResult := Char(Ord('0') + remainder) + hexResult
      else
        hexResult := Char(Ord('A') + (remainder - 10)) + hexResult;
      decimalNumber := decimalNumber div 16;
    end;
  end;
  DecimalToHex := hexResult;
end;

var
  decimalInput: LongInt;
  hexadecimalOutput: string;
begin
   TextColor(Red); // Set text color to Red
  WriteLn('This text will be displayed in red.');

  TextColor(White); // Set text color to White
  WriteLn('This text will be displayed in white.');

  ReadLn;
  Write('Entrez un nombre décimal : ');
  ReadLn(decimalInput);

  hexadecimalOutput := DecimalToHex(decimalInput);

  WriteLn('Le nombre hexadécimal correspondant est : ', hexadecimalOutput);
	Readln;
end.
