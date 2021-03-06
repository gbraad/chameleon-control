///-----------------------------------------------------------------
///
/// @file      ChFrm.h
/// @author    stefan
/// Created:   26.07.2010 09:12:50
/// @section   DESCRIPTION
///            ChFrm class declaration
///
///------------------------------------------------------------------



#ifndef __CHFRM_H__
#define __CHFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

#include <iostream>
#include <string>
//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/timer.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/gauge.h>
#include <wx/button.h>
////Header Include End
#include "Dbg.h"
#include "TaskMgr.h"
////Dialog Style Start
#undef ChFrm_STYLE
#define ChFrm_STYLE wxFULL_REPAINT_ON_RESIZE | wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX | wxFRAME_SHAPED
////Dialog Style End

class ChFrm : public wxFrame , public dbgOut
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		ChFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Chaco"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(801,501), long style = ChFrm_STYLE);
		virtual ~ChFrm();
                void WxButton1Click(wxCommandEvent& event);
                void WxSpinCtrl1Click(wxSpinEvent& event);
		void ChFrmActivate(wxActivateEvent& event);
		void WxButton1Click0(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void setText(wxDateTime now,std::string text);
		void WxButton3Click(wxCommandEvent& event);
		void outPrint(std::string);
		void setGauge(int pos);
		void WxButton4Click(wxCommandEvent& event);
		void WxButton6Click(wxCommandEvent& event);
		void WxButton5Click(wxCommandEvent& event);
		void GUIUpdate(wxTimerEvent& event);
		void filechooser2Click(wxCommandEvent& event);
		void memreaderClick(wxCommandEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void WxButton7Click(wxCommandEvent& event);
		void WxButton3Click0(wxCommandEvent& event);
		void bitmapprinterClick(wxCommandEvent& event);
		void setjtagslotClick(wxSpinEvent& event);
		void WxSpinCtrl2TextUpdated(wxCommandEvent& event );
		void writeImgButtonClick(wxCommandEvent& event);
		void WxButton3Click1(wxCommandEvent& event);
		void readImgButtonClick(wxCommandEvent& event);
		void writeSlotClick(wxCommandEvent& event);
		void readSlotClick(wxCommandEvent& event);
                void WxCheckBox1Click(wxCommandEvent& event);

		void setButtonStates(bool state);
                void StartBootloaderClick(wxCommandEvent& event);
	private:
                wxStaticText *WxStaticText7;
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTimer *WxTimer1;
                wxButton *StartBootloader;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
                wxStaticText *WxStaticText4;
		wxButton *readSlot;
		wxButton *writeSlot;
		wxButton *writeImgButton;
		wxButton *readImgButton;
		wxStaticText *WxStaticText3;
		wxSpinCtrl *WxSpinCtrl2;
		wxTextCtrl *WxEdit5;
		wxTextCtrl *WxEdit4;
		wxTextCtrl *WxEdit3;
		wxStaticText *WxStaticText2;
		wxTextCtrl *WxEdit2;
		wxSpinCtrl *WxSpinCtrl1;
		wxCheckBox *WxCheckBox1;
		wxButton *WxButton7;
		wxButton *memreader;
		wxStaticText *WxStaticText1;
		wxTextCtrl *WxEdit1;
		wxGauge *WxGauge1;
		wxButton *WxButton5;
		wxButton *WxButton2;
		wxButton *WxButton1;
		////GUI Control Declaration End
		
		wxTextCtrl * LogWindow;
		wxString * coreFilename;
		wxString * hexFilename;
		std::string coreFilenameStd;

		int coreNumber;

	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
                        ID_STARTBOOTLOADER = 1039,
			ID_WXTIMER1 = 1011,
                        ID_WXSTATICTEXT7 = 1038,
                        ID_WXSTATICTEXT6 = 1037,
			ID_WXSTATICTEXT5 = 1036,
			ID_WXSTATICTEXT4 = 1035,
			ID_READSLOT = 1034,
			ID_WRITESLOT = 1033,
			ID_WRITEIMGBUTTON = 1032,
			ID_READIMGBUTTON = 1030,
			ID_WXSTATICTEXT3 = 1029,
			ID_WXSPINCTRL2 = 1028,
			ID_WXEDIT5 = 1027,
			ID_WXEDIT4 = 1025,
			ID_WXEDIT3 = 1024,
			ID_WXSTATICTEXT2 = 1023,
			ID_WXEDIT2 = 1021,
			ID_WXSPINCTRL1 = 1020,
			ID_WXCHECKBOX1 = 1017,
			ID_WXBUTTON7 = 1016,
			ID_MEMREADER = 1015,
			ID_WXSTATICTEXT1 = 1014,
			ID_WXEDIT1 = 1013,
			ID_WXGAUGE1 = 1010,
			ID_WXBUTTON5 = 1008,
			ID_WXBUTTON2 = 1003,
			ID_WXBUTTON1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

wxString toWxString(std::string string);
std::string toStdString(wxString string);

#endif
