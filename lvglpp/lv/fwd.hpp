#pragma once
// Every class of the binding, declared and not defined.
// A signature only needs an incomplete type, so with this in scope no header has to
// include another just to name one -- which is what keeps the include graph acyclic
// (D-C8) without a forward declaration invented per use site.

namespace lv {

class _3dtexture;

class Anim;

class AnimTimeline;

class Animimg;

class Arc;

class Array;

class Bar;

class Button;

class ListButton;

class Buttonmatrix;

class CalendarHeaderDropdown;

class Calendar;

class Canvas;

class ChartCursor;

class ChartSeries;

class Chart;

class Checkbox;

class CircleBuf;

class Color16;

class ColorFilterDsc;

class Display;

class DrawArcDsc;

class DrawBlurDsc;

class DrawBorderDsc;

class DrawBoxShadowDsc;

class DrawBufHandlers;

class DrawBuf;

class DrawFillDsc;

class DrawGlyphDsc;

class DrawImageDsc;

class DrawLabelDsc;

class DrawLetterDsc;

class DrawLineDsc;

class DrawRectDsc;

class DrawTask;

class DrawTriangleDsc;

class DrawVectorDsc;

class Dropdown;

class EventDsc;

class Event;

class FileExplorer;

class FontInfo;

class FontManager;

class Font;

class FragmentManager;

class Fragment;

class FsDir;

class FsDrv;

class GltfModelLoader;

class GltfModelNode;

class GltfModel;

class Group;

class ImageDecoder;

class Image;

class Imagebutton;

class ImePinyin;

class Indev;

class Iter;

class Keyboard;

class Label;

class ListText;

class Layer;

class Led;

class Line;

class List;

class Ll;

class Lottie;

class Matrix;

class MemMonitor;

class MenuPage;

class Menu;

class MonkeyConfig;

class Monkey;

class Msgbox;

class ObjClass;

class CalendarHeaderArrow;

class Dropdownlist;

class MenuCont;

class MenuMainCont;

class MenuMainHeaderCont;

class MenuSection;

class MenuSeparator;

class MenuSidebarCont;

class MenuSidebarHeaderCont;

class MsgboxBackdrop;

class MsgboxContent;

class MsgboxFooter;

class MsgboxFooterButton;

class MsgboxHeader;

class MsgboxHeaderButton;

class Obj;

class Observer;

class PointPrecise;

class ProfilerBuiltinConfig;

class Rb;

class Roller;

class ScaleSection;

class Scale;

class Slider;

class Span;

class Spangroup;

class Spinbox;

class Spinner;

class StyleTransitionDsc;

class SubjectIncrementDsc;

class Subject;

class SvgNode;

class Switch;

class Table;

class Tabview;

class Textarea;

class Theme;

class Tileview;

class TileviewTile;

class Timer;

class TreeNode;

class VectorPath;

class Win;

class LocalStyle;

class Style;

class Point;

class Area;

class Color;

class ChildRange;

} // namespace lv
