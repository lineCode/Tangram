#pragma once
#include "dte.h"
using namespace VxDTE;

namespace VisualStudioPlus
{
	namespace VSEvents
	{
		extern _ATL_FUNC_INFO Click;
		extern _ATL_FUNC_INFO BuildBegin;
		extern _ATL_FUNC_INFO BuildDone;
		extern _ATL_FUNC_INFO BuildProjConfigBegin;
		extern _ATL_FUNC_INFO BuildProjConfigDone;
		extern _ATL_FUNC_INFO BeforeExecute;
		extern _ATL_FUNC_INFO AfterExecute;
		extern _ATL_FUNC_INFO EnterRunMode;
		extern _ATL_FUNC_INFO EnterDesignMode;
		extern _ATL_FUNC_INFO EnterBreakMode;
		extern _ATL_FUNC_INFO ExceptionThrown;
		extern _ATL_FUNC_INFO ExceptionNotHandled;
		extern _ATL_FUNC_INFO ContextChanged;
		extern _ATL_FUNC_INFO DocumentSaved;
		extern _ATL_FUNC_INFO DocumentClosing;
		extern _ATL_FUNC_INFO DocumentOpening;
		extern _ATL_FUNC_INFO DocumentOpened;
		extern _ATL_FUNC_INFO StartupComplete;
		extern _ATL_FUNC_INFO BeginShutdown;
		extern _ATL_FUNC_INFO ModeChanged;
		extern _ATL_FUNC_INFO MacrosRuntimeReset;
		extern _ATL_FUNC_INFO FindDoneType;
		extern _ATL_FUNC_INFO PaneAdded;
		extern _ATL_FUNC_INFO PaneUpdated;
		extern _ATL_FUNC_INFO PaneClearing;
		extern _ATL_FUNC_INFO ItemAdded;
		extern _ATL_FUNC_INFO ItemRemoved;
		extern _ATL_FUNC_INFO ItemRenamed;
		extern _ATL_FUNC_INFO Change;
		extern _ATL_FUNC_INFO Opened;
		extern _ATL_FUNC_INFO BeforeClosing;
		extern _ATL_FUNC_INFO AfterClosing;
		extern _ATL_FUNC_INFO QueryCloseSolution;
		extern _ATL_FUNC_INFO Renamed;
		extern _ATL_FUNC_INFO ProjectAdded;
		extern _ATL_FUNC_INFO ProjectRemoved;
		extern _ATL_FUNC_INFO ProjectRenamed;
		extern _ATL_FUNC_INFO TaskAdded;
		extern _ATL_FUNC_INFO TaskRemoved;
		extern _ATL_FUNC_INFO TaskModified;
		extern _ATL_FUNC_INFO TaskNavigated;
		extern _ATL_FUNC_INFO LineChanged;
		extern _ATL_FUNC_INFO WindowClosing;
		extern _ATL_FUNC_INFO WindowMoved;
		extern _ATL_FUNC_INFO WindowCreated;
		extern _ATL_FUNC_INFO WindowHiding;
		extern _ATL_FUNC_INFO WindowShowing;
		extern _ATL_FUNC_INFO WindowActivated;

		extern _ATL_FUNC_INFO BeforeKeyPress;
		extern _ATL_FUNC_INFO AfterKeyPress;

		extern _ATL_FUNC_INFO ElementAdded;
		extern _ATL_FUNC_INFO ElementChanged;
		extern _ATL_FUNC_INFO ElementDeleted;

		class CDTEBuildEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEBuildEvents, &__uuidof(_dispBuildEvents)>
		{
		public:
			virtual void __stdcall OnBuildBegin(vsBuildScope Scope, vsBuildAction Action) {}
			virtual void __stdcall OnBuildDone(vsBuildScope Scope, vsBuildAction Action) {}
			virtual void __stdcall OnBuildProjConfigBegin(BSTR Project, BSTR ProjectConfig, BSTR Platform, BSTR SolutionConfig) {}
			virtual void __stdcall OnBuildProjConfigDone(BSTR Project, BSTR ProjectConfig, BSTR Platform, BSTR SolutionConfig, VARIANT_BOOL Success) {}

			BEGIN_SINK_MAP(CDTEBuildEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispBuildEvents), /*dispid =*/ 0x00000003, OnBuildBegin, &BuildBegin)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispBuildEvents), /*dispid =*/ 0x00000004, OnBuildDone, &BuildDone)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispBuildEvents), /*dispid =*/ 0x00000005, OnBuildProjConfigBegin, &BuildProjConfigBegin)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispBuildEvents), /*dispid =*/ 0x00000006, OnBuildProjConfigDone, &BuildProjConfigDone)
			END_SINK_MAP()
		};

		class CDTECommandBarControlEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTECommandBarControlEvents, &__uuidof(VxDTE::_dispCommandBarControlEvents)>
		{
		public:
			virtual void __stdcall OnClick(IDispatch* CommandBarControl, VARIANT_BOOL* Handled, VARIANT_BOOL* CancelDefault) {}

			BEGIN_SINK_MAP(CDTECommandBarControlEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(VxDTE::_dispCommandBarControlEvents), /*dispid =*/ 0x00000001, OnClick, &Click)
			END_SINK_MAP()
		};

		class CDTECommandEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTECommandEvents, &__uuidof(_dispCommandEvents)>
		{
		public:
			virtual void __stdcall OnBeforeExecute(BSTR Guid, long ID, VARIANT CustomIn, VARIANT CustomOut, VARIANT_BOOL* CancelDefault) {}
			virtual void __stdcall OnAfterExecute(BSTR Guid, long ID, VARIANT CustomIn, VARIANT CustomOut) {}

			BEGIN_SINK_MAP(CDTECommandEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispCommandEvents), /*dispid =*/ 0x00000001, OnBeforeExecute, &BeforeExecute)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispCommandEvents), /*dispid =*/ 0x00000002, OnAfterExecute, &AfterExecute)
			END_SINK_MAP()
		};

		class CDTEDebuggerEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEDebuggerEvents, &__uuidof(_dispDebuggerEvents)>
		{
		public:
			virtual void __stdcall OnEnterRunMode(dbgEventReason Reason) {}
			virtual void __stdcall OnEnterDesignMode(dbgEventReason Reason) {}
			virtual void __stdcall OnEnterBreakMode(dbgEventReason Reason, dbgExecutionAction* ExecutionAction) {}
			virtual void __stdcall OnExceptionThrown(BSTR ExceptionType, BSTR Name, long Code, BSTR Description, dbgExceptionAction* ExceptionAction) {}
			virtual void __stdcall OnExceptionNotHandled(BSTR ExceptionType, BSTR Name, long Code, BSTR Description, dbgExceptionAction* ExceptionAction) {}
			virtual void __stdcall OnContextChanged(Process* NewProcess, Program* NewProgram, Thread* NewThread, StackFrame* NewStackFrame) {}

			BEGIN_SINK_MAP(CDTEDebuggerEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDebuggerEvents), /*dispid =*/ 0x00000001, OnEnterRunMode, &EnterRunMode)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDebuggerEvents), /*dispid =*/ 0x00000002, OnEnterDesignMode, &EnterDesignMode)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDebuggerEvents), /*dispid =*/ 0x00000003, OnEnterBreakMode, &EnterBreakMode)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDebuggerEvents), /*dispid =*/ 0x00000004, OnExceptionThrown, &ExceptionThrown)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDebuggerEvents), /*dispid =*/ 0x00000005, OnExceptionNotHandled, &ExceptionNotHandled)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDebuggerEvents), /*dispid =*/ 0x00000006, OnContextChanged, &ContextChanged)
			END_SINK_MAP()
		};

		class CDTEDocumentEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEDocumentEvents, &__uuidof(_dispDocumentEvents)>
		{
		public:
			virtual void __stdcall OnDocumentSaved(VxDTE::Document* Document) {}
			virtual void __stdcall OnDocumentClosing(VxDTE::Document* Document) {}
			virtual void __stdcall OnDocumentOpening(BSTR DocumentPath, VARIANT_BOOL ReadOnly) {}
			virtual void __stdcall OnDocumentOpened(VxDTE::Document* Document) {}

			BEGIN_SINK_MAP(CDTEDocumentEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDocumentEvents), /*dispid =*/ 0x00000001,OnDocumentSaved, &DocumentSaved)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDocumentEvents), /*dispid =*/ 0x00000002,OnDocumentClosing, &DocumentClosing)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDocumentEvents), /*dispid =*/ 0x00000003,OnDocumentOpening, &DocumentOpening)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDocumentEvents), /*dispid =*/ 0x00000004,OnDocumentOpened, &DocumentOpened)
			END_SINK_MAP()
		};

		class CDTEEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEEvents, &__uuidof(_dispDTEEvents)>
		{
		public:
			//virtual void __stdcall OnStartupComplete() {}
			virtual void __stdcall OnBeginShutdown() {}
			//virtual void __stdcall OnModeChanged(VxDTE::vsIDEMode LastMode) {}
			//virtual void __stdcall OnMacrosRuntimeReset() {}

			BEGIN_SINK_MAP(CDTEEvents)
				//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDTEEvents), /*dispid =*/ 0x00000001, OnStartupComplete, &StartupComplete)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDTEEvents), /*dispid =*/ 0x00000002, OnBeginShutdown, &BeginShutdown)
				//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDTEEvents), /*dispid =*/ 0x00000003, OnModeChanged, &ModeChanged)
				//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispDTEEvents), /*dispid =*/ 0x00000004, OnMacrosRuntimeReset, &MacrosRuntimeReset)
			END_SINK_MAP()
		};

		class CDTEFindEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEFindEvents, &__uuidof(_dispFindEvents)>
		{
		public:
			virtual void __stdcall OnFindDone(vsFindResult Result, VARIANT_BOOL Cancelled) {}

			BEGIN_SINK_MAP(CDTEFindEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispFindEvents), /*dispid =*/ 0x00000001, OnFindDone, &FindDoneType)
			END_SINK_MAP()
		};

		class CDTEOutputWindowEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEOutputWindowEvents, &__uuidof(_dispOutputWindowEvents)>
		{
		public:
			virtual void __stdcall OnPaneAdded(OutputWindowPane* pPane) {}
			virtual void __stdcall OnPaneUpdated(OutputWindowPane* pPane) {}
			virtual void __stdcall OnPaneClearing(OutputWindowPane* pPane) {}

			BEGIN_SINK_MAP(CDTEOutputWindowEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispOutputWindowEvents), /*dispid =*/ 0x00000001, OnPaneAdded, &PaneAdded)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispOutputWindowEvents), /*dispid =*/ 0x00000002, OnPaneUpdated, &PaneUpdated)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispOutputWindowEvents), /*dispid =*/ 0x00000003, OnPaneClearing, &PaneClearing)
			END_SINK_MAP()
		};

		class CDTEProjectItemsEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEProjectItemsEvents, &__uuidof(_dispProjectItemsEvents)>
		{
		public:
			virtual void __stdcall OnItemAdded(ProjectItem* ProjectItem) {}
			virtual void __stdcall OnItemRemoved(ProjectItem* ProjectItem) {}
			virtual void __stdcall OnItemRenamed(ProjectItem* ProjectItem, BSTR OldName) {}

			BEGIN_SINK_MAP(CDTEProjectItemsEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispProjectItemsEvents), /*dispid =*/ 0x00000001, OnItemAdded, &ItemAdded)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispProjectItemsEvents), /*dispid =*/ 0x00000002, OnItemRemoved, &ItemRemoved)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispProjectItemsEvents), /*dispid =*/ 0x00000003, OnItemRenamed, &ItemRenamed)
			END_SINK_MAP()
		};

		class CDTEProjectsEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEProjectsEvents, &__uuidof(_dispProjectsEvents)>
		{
		public:
			virtual void __stdcall OnItemAdded(VxDTE::Project* Project) {}
			virtual void __stdcall OnItemRemoved(VxDTE::Project* Project) {}
			virtual void __stdcall OnItemRenamed(VxDTE::Project* Project, BSTR OldName) {}

			BEGIN_SINK_MAP(CDTEProjectsEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispProjectsEvents), /*dispid =*/ 0x00000001, OnItemAdded, &ItemAdded)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispProjectsEvents), /*dispid =*/ 0x00000002, OnItemRemoved, &ItemRemoved)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispProjectsEvents), /*dispid =*/ 0x00000003, OnItemRenamed, &ItemRenamed)
			END_SINK_MAP()
		};

		class CDTESelectionEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTESelectionEvents, &__uuidof(_dispSelectionEvents)>
		{
		public:
			virtual void __stdcall OnChange() {}

			BEGIN_SINK_MAP(CDTESelectionEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSelectionEvents), /*dispid =*/ 0x00000001, OnChange, &Change)
			END_SINK_MAP()
		};

		class CDTESolutionEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTESolutionEvents, &__uuidof(_dispSolutionEvents)>
		{
		public:
			virtual void __stdcall OnOpened() {}
			virtual void __stdcall OnBeforeClosing() {}
			virtual void __stdcall OnAfterClosing() {}
			virtual void __stdcall OnQueryCloseSolution(VARIANT_BOOL* fCancel) {}
			virtual void __stdcall OnRenamed(BSTR OldName) {}
			virtual void __stdcall OnProjectAdded(VxDTE::Project* Project) {}
			virtual void __stdcall OnProjectRemoved(VxDTE::Project* Project) {}
			virtual void __stdcall OnProjectRenamed(VxDTE::Project* Project, BSTR OldName) {}

			BEGIN_SINK_MAP(CDTESolutionEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSolutionEvents), /*dispid =*/ 0x00000001, OnOpened, &Opened)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSolutionEvents), /*dispid =*/ 0x00000002, OnBeforeClosing, &BeforeClosing)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSolutionEvents), /*dispid =*/ 0x00000003, OnAfterClosing, &AfterClosing)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSolutionEvents), /*dispid =*/ 0x00000004, OnQueryCloseSolution, &QueryCloseSolution)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSolutionEvents), /*dispid =*/ 0x00000005, OnRenamed, &Renamed)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSolutionEvents), /*dispid =*/ 0x00000006, OnProjectAdded, &ProjectAdded)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSolutionEvents), /*dispid =*/ 0x00000007, OnProjectRemoved, &ProjectRemoved)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispSolutionEvents), /*dispid =*/ 0x00000008, OnProjectRenamed, &ProjectRenamed)
			END_SINK_MAP()
		};

		class CDTETaskListEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTETaskListEvents, &__uuidof(VxDTE::_dispTaskListEvents)>
		{
		public:
			virtual void __stdcall OnTaskAdded(TaskItem* TaskItem) {}
			virtual void __stdcall OnTaskRemoved(TaskItem* TaskItem) {}
			virtual void __stdcall OnTaskModified(TaskItem* TaskItem, vsTaskListColumn ColumnModified) {}
			virtual void __stdcall OnTaskNavigated(TaskItem* TaskItem, VARIANT_BOOL* NavigateHandled) {}

			BEGIN_SINK_MAP(CDTETaskListEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispTaskListEvents), /*dispid =*/ 0x00000001, OnTaskAdded, &TaskAdded)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispTaskListEvents), /*dispid =*/ 0x00000002, OnTaskRemoved, &TaskRemoved)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispTaskListEvents), /*dispid =*/ 0x00000003, OnTaskModified, &TaskModified)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispTaskListEvents), /*dispid =*/ 0x00000004, OnTaskNavigated, &TaskNavigated)
			END_SINK_MAP()
		};

		class CDTETextEditorEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTETextEditorEvents, &__uuidof(VxDTE::_dispTextEditorEvents)>
		{
		public:
			virtual void __stdcall OnLineChanged(VxDTE::TextPoint* StartPoint, VxDTE::TextPoint* EndPoint, long Hint) {}

			BEGIN_SINK_MAP(CDTETextEditorEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(VxDTE::_dispTextEditorEvents), /*dispid =*/ 0x00000001, OnLineChanged, &LineChanged)
			END_SINK_MAP()
		};

		class CDTEWindowEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEWindowEvents, &__uuidof(_dispWindowEvents)>
		{
		public:
			//virtual void __stdcall OnWindowClosing(VxDTE::Window* Window) {}
			//virtual void __stdcall OnWindowMoved(VxDTE::Window* Window, long Top, long Left, long Width, long Height) {}
			virtual void __stdcall OnWindowActivated(VxDTE::Window* GotFocus, VxDTE::Window* LostFocus) {}
			virtual void __stdcall OnWindowCreated(VxDTE::Window* Window) {}

			BEGIN_SINK_MAP(CDTEWindowEvents)
				//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(VxDTE::_dispWindowEvents), /*dispid =*/ 0x00000001,OnWindowClosing, &WindowClosing)
				//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(VxDTE::_dispWindowEvents), /*dispid =*/ 0x00000002,OnWindowMoved, &WindowMoved)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispWindowEvents), /*dispid =*/ 0x00000003,OnWindowActivated, &WindowActivated)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispWindowEvents), /*dispid =*/ 0x00000004,OnWindowCreated, &WindowCreated)
			END_SINK_MAP()
		};

		class CDTEWindowVisibilityEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTEWindowVisibilityEvents, &__uuidof(_dispWindowVisibilityEvents)>
		{
		public:
			virtual void __stdcall OnWindowHiding(VxDTE::Window* Window) {}
			virtual void __stdcall OnWindowShowing(VxDTE::Window* Window) {}

			BEGIN_SINK_MAP(CDTEWindowVisibilityEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispWindowVisibilityEvents), /*dispid =*/ 0x00000001, OnWindowHiding, &WindowHiding)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispWindowVisibilityEvents), /*dispid =*/ 0x00000002, OnWindowShowing, &WindowShowing)
			END_SINK_MAP()
		};		

		class CDTETextDocumentKeyPressEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTETextDocumentKeyPressEvents, &__uuidof(_dispTextDocumentKeyPressEvents)>
		{
		public:
			virtual void __stdcall OnBeforeKeyPress(BSTR Keypress, VxDTE::TextSelection * Selection, VARIANT_BOOL InStatementCompletion, VARIANT_BOOL * CancelKeypress) {}
			virtual void __stdcall OnAfterKeyPress(BSTR Keypress, VxDTE::TextSelection * Selection, VARIANT_BOOL InStatementCompletion) {}

			BEGIN_SINK_MAP(CDTETextDocumentKeyPressEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispTextDocumentKeyPressEvents), /*dispid =*/ 0x00000001, OnBeforeKeyPress, &BeforeKeyPress)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispTextDocumentKeyPressEvents), /*dispid =*/ 0x00000002, OnAfterKeyPress, &AfterKeyPress)
			END_SINK_MAP()
		};		

		class CDTECodeModelEvents : public IDispEventSimpleImpl</*nID =*/ 1, CDTECodeModelEvents, &__uuidof(_dispCodeModelEvents)>
		{
		public:
			virtual void __stdcall OnElementAdded(VxDTE::CodeElement * Element) {}
			virtual void __stdcall OnElementChanged(VxDTE::CodeElement * Element, enum vsCMChangeKind Change) {}
			virtual void __stdcall OnElementDeleted(IDispatch * Parent, VxDTE::CodeElement * Element) {}

			BEGIN_SINK_MAP(CDTECodeModelEvents)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispCodeModelEvents), /*dispid =*/ 0x00000001, OnElementAdded, &ElementAdded)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispCodeModelEvents), /*dispid =*/ 0x00000002, OnElementChanged, &ElementChanged)
				SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_dispCodeModelEvents), /*dispid =*/ 0x00000004, OnElementDeleted, &ElementDeleted)
			END_SINK_MAP()
		};		
	}
}
