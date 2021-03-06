[Variables]
Uptime_X=1436
;Left, Right or Center
UpTime_Anchor=Right
UpTime_Width=(#Font_Size#*8.5)

[Metadata]
Name=Fedina\\Uptime
Author=reddit.com/u/khanhas
Description=Display up time.

[UpTimeAnchor]
Measure=String
String = #UpTime_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption UpTimeShape X "(#Bar_OffsetX#+#*UpTime_X*#-#UpTime_Width#/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption UpTimeShape X "(#Bar_OffsetX#+#*UpTime_X*#-#UpTime_Width#)"]

[MeasureUptime]
Measure=upTime
Format="%3!i!h %2!i!m"

[UpTimeShape]
Meter=Shape
X=(#Bar_OffsetX#+#UpTime_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,#UpTime_Width#,#Bar_Height# | StrokeWidth 0 | Extend Color
Color = Fill Color [ColorMeasureScript:GetColor('#Color_Scheme3#', '#Color_Scheme4#', 'side to middle', #Uptime_X#)]
DynamicVariables=1

[UptimeIcon]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=([UpTimeShape:X] + [UpTimeShape:W]/2 - ([UpTimeIcon:W] + [UpTime:W] + 5)/2)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[Uptime]
Meter=String
MeasureName=MeasureUptime
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=5R
Y=r
