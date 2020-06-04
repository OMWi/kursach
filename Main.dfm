object Form1: TForm1
  Left = -55
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 586
  ClientWidth = 902
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  WindowState = wsMaximized
  OnKeyUp = FormKeyUp
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 656
    Top = 280
    Width = 84
    Height = 13
    Caption = 'Congratulations!!'
    Visible = False
  end
  object Label2: TLabel
    Left = 646
    Top = 312
    Width = 108
    Height = 13
    Caption = 'You escaped the maze'
    Visible = False
  end
  object Button1: TButton
    Left = 680
    Top = 185
    Width = 75
    Height = 25
    Caption = 'Generate'
    TabOrder = 0
    TabStop = False
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 680
    Top = 216
    Width = 74
    Height = 21
    TabStop = False
    Alignment = taCenter
    AutoSize = False
    NumbersOnly = True
    TabOrder = 1
    TextHint = 'Size of maze'
  end
end
