// Created by Microsoft (R) C/C++ Compiler Version 15.00.21022.08 (c4bcb6c1).
//
// d:\tangram - 20130414\testatl\debug\msprj.tlh
//
// C++ source equivalent of Win32 type library D:\wordplus\MSPRJ.OLB
// compiler-generated file created 05/15/13 at 17:27:29 - DO NOT EDIT!

//
// Cross-referenced type libraries:
//
#include "mso.h"
//

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace MSProject {

//
// Forward references and typedefs
//

struct __declspec(uuid("a7107640-94df-1068-855e-00dd01075445"))
/* LIBID */ __MSProject;
enum PjMonth;
enum PjAccrueAt;
enum PjDateFormat;
enum PjConstraint;
enum PjGridline;
enum PjBarSize;
enum PjAlignment;
enum PjVerticalAlignment;
enum PjBarEndShape;
enum PjBarItem;
enum PjBarShape;
enum PjBarType;
enum PjBorder;
enum PjCalculation;
enum PjCalendarBarType;
enum PjCalendarDateLabel;
enum PjCalendarShading;
enum PjColor;
enum PjCreatePublisher;
enum PjCustomizeMailAction;
enum PjDateLabel;
enum PjDateOrder;
enum PjDayLabel;
enum PjDialog;
enum PjAssignmentField;
enum PjField;
enum PjCustomField;
enum PjCustomFieldAttribute;
enum PjSummaryCalc;
enum PjCriteriaList;
enum PjIndicator;
enum PjComparison;
enum PjListOrder;
enum PjValueListItem;
enum PjFileFormat;
enum PjFillPattern;
enum PjFormatUnit;
enum PjGanttBarLink;
enum PjLegend;
enum PjLevelOrder;
enum PjCostRateTable;
enum PjLevelPeriodBasis;
enum PjMailField;
enum PjMailSystem;
enum PjMergeType;
enum PjMessageType;
enum PjMonthLabel;
enum PjNonWorkingPlacement;
enum PjYesNoAutomatic;
enum PjOrganizer;
enum PjPageSetupCalendarItem;
enum PjPERTField;
enum PjPERTBoxSize;
enum PjPERTBoxStyle;
enum PjPlacement;
enum PjPoolAction;
enum PjPriority;
enum PjProjectUpdate;
enum PjPublishAction;
enum PjEditionUpdate;
enum PjResAssignOperation;
enum PjResourceGraphStyle;
enum PjSaveType;
enum PjSaveBaselineFrom;
enum PjSaveBaselineTo;
enum PjScheduleProjectFrom;
enum PjViewScreen;
enum PjShape;
enum PjSubscribeAction;
enum PjSubscribeFormat;
enum PjTaskLinkType;
enum PjTaskFixedType;
enum PjWorkContourType;
enum PjInformationTab;
enum PjTextItem;
enum PjTimescaledData;
enum PjTimescaleUnit;
enum PjTaskTimescaledData;
enum PjResourceTimescaledData;
enum PjAssignmentTimescaledData;
enum PjToolbarAction;
enum PjUnit;
enum PjWeekday;
enum PjWeekLabel;
enum PjWindowState;
enum PjResourceGraphPattern;
enum PjLineType;
enum PjPasteSpecialType;
enum PjFieldType;
enum PjEnableCancelKey;
enum PjPhoneticType;
enum PjAssignmentUnits;
enum PjPoolOpen;
enum PjOldConstants;
enum PjCopyPictureFor;
enum PjIMEMode;
enum PjCopyPictureRows;
enum PjWorkgroupMessages;
enum PjImportMethods;
enum PjTextFileOrigin;
enum PjDataCategories;
enum PjTeamStatusCompletedWork;
enum PjMSApplication;
enum PjWBSSequence;
enum PjCustomOutlineCodeSequence;
enum PjResourceTypes;
enum PjBoxStyle;
enum PjBoxShape;
enum PjDataTemplate;
enum PjCell;
enum PjBoxSet;
enum PjGroupOn;
enum PjAuthentication;
enum PjAccountType;
enum PjBackgroundPattern;
enum PjAutomaticSaveOptions;
enum PJTaskOutlineShowLevel;
enum PjLayoutMode;
enum PjLayoutScheme;
enum PjRowColSize;
enum PjLinkStyle;
enum PjLinkColorMode;
enum PjAlign;
enum PjCopyPictureScaleOption;
enum PjPaperSize;
struct __declspec(uuid("000c0c3f-0000-0000-c000-000000000046"))
/* dual interface */ Task;
struct __declspec(uuid("000c0c41-0000-0000-c000-000000000046"))
/* dual interface */ Resource;
struct __declspec(uuid("000c0c43-0000-0000-c000-000000000046"))
/* dual interface */ Calendar;
struct __declspec(uuid("000c0c45-0000-0000-c000-000000000046"))
/* dual interface */ Assignment;
struct __declspec(uuid("000c0c4a-0000-0000-c000-000000000046"))
/* dual interface */ Years;
struct __declspec(uuid("000c0c4c-0000-0000-c000-000000000046"))
/* dual interface */ Months;
struct __declspec(uuid("000c0c51-0000-0000-c000-000000000046"))
/* dual interface */ Days;
struct __declspec(uuid("00020b17-0000-0000-c000-000000000046"))
/* dispinterface */ List;
struct __declspec(uuid("00020b18-0000-0000-c000-000000000046"))
/* dispinterface */ Selection;
struct __declspec(uuid("00020b19-0000-0000-c000-000000000046"))
/* dispinterface */ Cell;
struct __declspec(uuid("00020b1c-0000-0000-c000-000000000046"))
/* dual interface */ Subproject;
struct __declspec(uuid("00020b1b-0000-0000-c000-000000000046"))
/* dual interface */ Subprojects;
struct __declspec(uuid("11589054-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ TaskGroups;
struct __declspec(uuid("11589055-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ ResourceGroups;
struct __declspec(uuid("11589051-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ Group;
struct __declspec(uuid("11589052-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ GroupCriteria;
struct __declspec(uuid("11589053-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ GroupCriterion;
struct __declspec(uuid("000c0c4e-0000-0000-c000-000000000046"))
/* dual interface */ WeekDays;
struct __declspec(uuid("000c0c4f-0000-0000-c000-000000000046"))
/* dual interface */ WeekDay;
struct __declspec(uuid("000c0c50-0000-0000-c000-000000000046"))
/* dual interface */ Shift;
struct __declspec(uuid("000c0c49-0000-0000-c000-000000000046"))
/* dual interface */ Period;
struct __declspec(uuid("000c0c4b-0000-0000-c000-000000000046"))
/* dual interface */ Year;
struct __declspec(uuid("000c0c4d-0000-0000-c000-000000000046"))
/* dual interface */ Month;
struct __declspec(uuid("000c0c52-0000-0000-c000-000000000046"))
/* dual interface */ Day;
struct __declspec(uuid("000c0c54-0000-0000-c000-000000000046"))
/* dual interface */ TimeScaleValue;
struct __declspec(uuid("000c0c53-0000-0000-c000-000000000046"))
/* dual interface */ TimeScaleValues;
struct __declspec(uuid("000c0c56-0000-0000-c000-000000000046"))
/* dual interface */ CostRateTable;
struct __declspec(uuid("000c0c55-0000-0000-c000-000000000046"))
/* dual interface */ CostRateTables;
struct __declspec(uuid("000c0c58-0000-0000-c000-000000000046"))
/* dual interface */ PayRate;
struct __declspec(uuid("000c0c57-0000-0000-c000-000000000046"))
/* dual interface */ PayRates;
struct __declspec(uuid("1251566d-2bdf-11d2-9eac-00c04fb92e6f"))
/* dual interface */ Availability;
struct __declspec(uuid("1251566c-2bdf-11d2-9eac-00c04fb92e6f"))
/* dual interface */ Availabilities;
struct __declspec(uuid("a7c6acb0-58c6-11d2-ae5a-00c04fb6f701"))
/* dual interface */ TaskDependency;
struct __declspec(uuid("a7c6acb1-58c6-11d2-ae5a-00c04fb6f701"))
/* dual interface */ TaskDependencies;
struct __declspec(uuid("00020b04-0000-0000-c000-000000000046"))
/* dispinterface */ Pane;
struct __declspec(uuid("00020b02-0000-0000-c000-000000000046"))
/* dispinterface */ Window;
struct __declspec(uuid("00020b03-0000-0000-c000-000000000046"))
/* dispinterface */ Windows;
struct __declspec(uuid("000c0c48-0000-0000-c000-000000000046"))
/* dual interface */ SplitPart;
struct __declspec(uuid("000c0c47-0000-0000-c000-000000000046"))
/* dual interface */ SplitParts;
struct __declspec(uuid("000c0c40-0000-0000-c000-000000000046"))
/* dual interface */ Tasks;
struct __declspec(uuid("000c0c42-0000-0000-c000-000000000046"))
/* dual interface */ Resources;
struct __declspec(uuid("000c0c46-0000-0000-c000-000000000046"))
/* dual interface */ Assignments;
struct __declspec(uuid("000c0c44-0000-0000-c000-000000000046"))
/* dual interface */ Calendars;
struct __declspec(uuid("00020b00-0000-0000-c000-000000000046"))
/* dispinterface */ _IProjectDoc;
struct __declspec(uuid("f81dd3c0-5089-11cf-a49d-00aa00574c74"))
/* dispinterface */ _EProjectDoc;
struct /* coclass */ Project;
struct __declspec(uuid("00020b01-0000-0000-c000-000000000046"))
/* dispinterface */ Projects;
struct __declspec(uuid("78e9f620-ebc0-11cf-a523-00a0c904de55"))
/* dispinterface */ _Global;
struct __declspec(uuid("00020aff-0000-0000-c000-000000000046"))
/* dispinterface */ _MSProject;
struct __declspec(uuid("7b7597d0-0c9f-11d0-8c43-00a0c904dcd4"))
/* dispinterface */ _EProjectApp;
struct /* coclass */ Application;
struct /* coclass */ Global;
enum PjBaselines;
enum PjStatusType;
enum PjCheckOutType;
enum PjAssignResourcesListFields;
enum PjLoginType;
enum PjProfileType;
enum PjProfileConnectionState;
enum PjResourceRequestType;
enum PjEditionType;
enum PjResSubstitutionPoolOption;
enum PjServerVersionInfo;
enum PjProjectType;
enum PjEarnedValueMethod;
enum PjSpellingField;
enum PjItemType;
enum PjPublishInformationOnSave;
enum PjPublishScope;
enum PjProjectServerTrackingMethod;
struct __declspec(uuid("11589050-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ Groups;
struct __declspec(uuid("4cf32482-106b-4fff-a1ab-7dd395fb0958"))
/* dual interface */ Views;
struct __declspec(uuid("b4097887-ec12-4683-9622-9974ef26353c"))
/* dual interface */ ViewsSingle;
struct __declspec(uuid("ce4f7d83-369b-43cf-96a8-29c2de2b8658"))
/* dual interface */ ViewsCombination;
struct __declspec(uuid("103ef3dc-9fce-4611-8c8b-f306c8881ca5"))
/* dual interface */ View;
struct __declspec(uuid("f15fde9e-fdc1-44d2-a0d0-249ad48f58fe"))
/* dual interface */ ViewSingle;
struct __declspec(uuid("0880e27c-c621-4349-96ad-56520c827e14"))
/* dual interface */ ViewCombination;
struct __declspec(uuid("31e3eb5a-6339-43b0-b1b8-1aed03886aec"))
/* dual interface */ Tables;
struct __declspec(uuid("54eff41a-4603-4771-80ee-f313bf9faec2"))
/* dual interface */ Table;
struct __declspec(uuid("ed989e98-f561-4d58-8f67-5d2e2b920e77"))
/* dual interface */ Filters;
struct __declspec(uuid("dc2fddaf-ce01-42dc-bb4f-b3fb3346d5b7"))
/* dual interface */ Filter;
struct __declspec(uuid("02497005-3861-4603-80a4-ff309631dba1"))
/* dual interface */ EventInfo;
struct __declspec(uuid("6711f81e-aa55-47ee-aa9f-31b00e709cb6"))
/* dual interface */ Profile;
struct __declspec(uuid("08cd6de7-87cd-42ab-bd28-6e2c0170a274"))
/* dual interface */ Profiles;
struct __declspec(uuid("bf6d2103-92d3-4162-9816-a3d811bcf8ca"))
/* dual interface */ TableFields;
struct __declspec(uuid("747d4ba8-fb3b-4c2c-b615-02cb6ebf0ae7"))
/* dual interface */ TableField;
struct __declspec(uuid("5066d7c4-1ed7-48c4-ace7-299e109d368c"))
/* dispinterface */ _EProjectApp2;
enum PjBookingTypes;
enum PjMeasurementUnits;
struct __declspec(uuid("30dff087-4ddc-4166-93b2-a9c259c1e4ad"))
/* dual interface */ OutlineCode;
struct __declspec(uuid("4269779b-f035-4e2f-abdd-54b6d94a2a03"))
/* dual interface */ OutlineCodes;
struct __declspec(uuid("c19e7deb-c19b-4294-bc60-5b2d99c00398"))
/* dual interface */ LookupTableEntry;
struct __declspec(uuid("da33f25e-ad36-48b9-9cb6-cdb0cf6ee070"))
/* dual interface */ LookupTable;
struct __declspec(uuid("e75e1380-8623-41c9-9920-508f676c4575"))
/* dual interface */ CodeMaskLevel;
struct __declspec(uuid("4cc10f2b-7df1-413c-a44d-9ab35adfd9ae"))
/* dual interface */ CodeMask;
struct __declspec(uuid("00020b05-0000-0000-c000-000000000046"))
/* dispinterface */ Windows2;
enum PjCustomFieldType;
enum PjExceptionType;
enum PjExceptionPosition;
enum PjExceptionItem;
enum PjCommitmentTaskLinkType;
enum PjVisualReportsTab;
enum PjVisualReportsTemplateType;
enum PjVisualReportsCubeType;
enum PjVisualReportsDataLevel;
enum PjCalendarType;
enum PjRecalcDriverType;
enum PjIsCommandEnabled;
enum PjThemeElement;
enum PjLegacyFileFormats;
struct __declspec(uuid("936f4d59-007b-4f7b-8932-90a40fc44391"))
/* dual interface */ Exception;
struct __declspec(uuid("9dbaec97-ada1-4488-8845-818e734f182e"))
/* dual interface */ Exceptions;
struct __declspec(uuid("22228b77-f739-46a2-bf45-eee43a936f06"))
/* dual interface */ WorkWeek;
struct __declspec(uuid("1137eff0-691f-4f78-9647-40fe8e500d34"))
/* dual interface */ WorkWeeks;
struct __declspec(uuid("1f4f463f-eb4b-4d2e-86ed-61a9cfa41e89"))
/* dual interface */ WorkWeekDays;
struct __declspec(uuid("9bc789c9-50c6-476f-a96c-d46e95b4c901"))
/* dual interface */ WorkWeekDay;
struct __declspec(uuid("46bff766-f07a-409c-a85f-eed0a36589f9"))
/* dual interface */ ReportTemplate;
struct __declspec(uuid("5918f188-19be-401e-a702-fee268804738"))
/* dual interface */ ReportTemplates;
struct __declspec(uuid("9dd14141-f0a9-4692-8288-a6835f93dc8a"))
/* dual interface */ StartDriver;
struct __declspec(uuid("9dd14142-f0a9-4692-8288-a6835f93dc8a"))
/* dual interface */ ActualStartDrivers;
struct __declspec(uuid("9dd14143-f0a9-4692-8288-a6835f93dc8a"))
/* dual interface */ PredecessorDrivers;
struct __declspec(uuid("9dd14144-f0a9-4692-8288-a6835f93dc8a"))
/* dual interface */ ChildDrivers;
struct __declspec(uuid("9dd14145-f0a9-4692-8288-a6835f93dc8a"))
/* dual interface */ CalendarDrivers;
enum PjLevelSelectedOption;
enum PjTimelineShowHide;
enum PjTimelineInsertTaskType;
enum PjNewTasksStartOnDate;
enum PjTeamPlannerStyle;
enum PjFieldTypes;
enum PjAutoFilterType;
enum PjDocExportType;
enum PjTaskWarnings;
enum PjViewType;
enum PjCompareVersionItems;
enum PjCompareVersionColumns;
enum PjAssignmentReplanAction;
enum PjOptionsSecurityTab;
enum PjServerPage;
enum PjFilterViewType;
enum PjOverallocationType;
struct __declspec(uuid("1158905a-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ TaskGroups2;
struct __declspec(uuid("1158905b-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ ResourceGroups2;
struct __declspec(uuid("11589058-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ Group2;
struct __declspec(uuid("11589056-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ GroupCriteria2;
struct __declspec(uuid("11589057-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ GroupCriterion2;
struct __declspec(uuid("11589059-69f0-11d2-b889-00c04fb90729"))
/* dual interface */ Groups2;
struct __declspec(uuid("9dd14146-f0a9-4692-8288-a6835f93dc8a"))
/* dual interface */ OverAllocatedAssignments;
enum PjReportLayoutTemplateId;
enum PjCacheJobState;
enum PjJobType;
struct __declspec(uuid("ff59cfba-cb6f-4b92-a7d2-97d1cab6ebff"))
/* dual interface */ Reports;
struct __declspec(uuid("c4f74db0-e706-4ad5-9e71-ad5e6a0cf388"))
/* dual interface */ Report;
struct __declspec(uuid("7300bad0-c853-475e-80a7-2fa3a286f91f"))
/* dual interface */ Shape;
struct __declspec(uuid("c6984804-2c4d-4874-b69f-c14bf97c0bf1"))
/* dual interface */ Shapes;
struct __declspec(uuid("f7f947d7-dda9-47cb-842e-7de3927f1a68"))
/* dual interface */ ShapeRange;
struct __declspec(uuid("ca6893a3-e8b7-46ed-89ab-0600354cbd7b"))
/* dual interface */ Chart;
struct __declspec(uuid("33daa9fa-94ca-414e-bcf4-3e260b02b55e"))
/* dual interface */ ReportTable;
struct __declspec(uuid("da4986e8-ff38-4c85-881a-78f79f1436d9"))
/* dual interface */ Series;
struct __declspec(uuid("787fbde2-e363-48aa-94e1-fb94474770b7"))
/* dual interface */ SeriesCollection;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(List, __uuidof(List));
_COM_SMARTPTR_TYPEDEF(Selection, __uuidof(Selection));
_COM_SMARTPTR_TYPEDEF(Cell, __uuidof(Cell));
_COM_SMARTPTR_TYPEDEF(Pane, __uuidof(Pane));
_COM_SMARTPTR_TYPEDEF(Window, __uuidof(Window));
_COM_SMARTPTR_TYPEDEF(Windows, __uuidof(Windows));
_COM_SMARTPTR_TYPEDEF(_IProjectDoc, __uuidof(_IProjectDoc));
_COM_SMARTPTR_TYPEDEF(_EProjectDoc, __uuidof(_EProjectDoc));
_COM_SMARTPTR_TYPEDEF(Projects, __uuidof(Projects));
_COM_SMARTPTR_TYPEDEF(_Global, __uuidof(_Global));
_COM_SMARTPTR_TYPEDEF(_MSProject, __uuidof(_MSProject));
_COM_SMARTPTR_TYPEDEF(_EProjectApp, __uuidof(_EProjectApp));
_COM_SMARTPTR_TYPEDEF(Shift, __uuidof(Shift));
_COM_SMARTPTR_TYPEDEF(TimeScaleValue, __uuidof(TimeScaleValue));
_COM_SMARTPTR_TYPEDEF(TimeScaleValues, __uuidof(TimeScaleValues));
_COM_SMARTPTR_TYPEDEF(SplitPart, __uuidof(SplitPart));
_COM_SMARTPTR_TYPEDEF(SplitParts, __uuidof(SplitParts));
_COM_SMARTPTR_TYPEDEF(View, __uuidof(View));
_COM_SMARTPTR_TYPEDEF(Views, __uuidof(Views));
_COM_SMARTPTR_TYPEDEF(Filter, __uuidof(Filter));
_COM_SMARTPTR_TYPEDEF(Filters, __uuidof(Filters));
_COM_SMARTPTR_TYPEDEF(EventInfo, __uuidof(EventInfo));
_COM_SMARTPTR_TYPEDEF(Profile, __uuidof(Profile));
_COM_SMARTPTR_TYPEDEF(Profiles, __uuidof(Profiles));
_COM_SMARTPTR_TYPEDEF(_EProjectApp2, __uuidof(_EProjectApp2));
_COM_SMARTPTR_TYPEDEF(Windows2, __uuidof(Windows2));
_COM_SMARTPTR_TYPEDEF(ReportTemplate, __uuidof(ReportTemplate));
_COM_SMARTPTR_TYPEDEF(ReportTemplates, __uuidof(ReportTemplates));
_COM_SMARTPTR_TYPEDEF(ReportTable, __uuidof(ReportTable));
_COM_SMARTPTR_TYPEDEF(Series, __uuidof(Series));
_COM_SMARTPTR_TYPEDEF(SeriesCollection, __uuidof(SeriesCollection));
_COM_SMARTPTR_TYPEDEF(Task, __uuidof(Task));
_COM_SMARTPTR_TYPEDEF(Subproject, __uuidof(Subproject));
_COM_SMARTPTR_TYPEDEF(Subprojects, __uuidof(Subprojects));
_COM_SMARTPTR_TYPEDEF(TaskDependency, __uuidof(TaskDependency));
_COM_SMARTPTR_TYPEDEF(TaskDependencies, __uuidof(TaskDependencies));
_COM_SMARTPTR_TYPEDEF(Tasks, __uuidof(Tasks));
_COM_SMARTPTR_TYPEDEF(PredecessorDrivers, __uuidof(PredecessorDrivers));
_COM_SMARTPTR_TYPEDEF(ChildDrivers, __uuidof(ChildDrivers));
_COM_SMARTPTR_TYPEDEF(Resource, __uuidof(Resource));
_COM_SMARTPTR_TYPEDEF(Assignment, __uuidof(Assignment));
_COM_SMARTPTR_TYPEDEF(PayRate, __uuidof(PayRate));
_COM_SMARTPTR_TYPEDEF(PayRates, __uuidof(PayRates));
_COM_SMARTPTR_TYPEDEF(CostRateTable, __uuidof(CostRateTable));
_COM_SMARTPTR_TYPEDEF(CostRateTables, __uuidof(CostRateTables));
_COM_SMARTPTR_TYPEDEF(Availability, __uuidof(Availability));
_COM_SMARTPTR_TYPEDEF(Availabilities, __uuidof(Availabilities));
_COM_SMARTPTR_TYPEDEF(Resources, __uuidof(Resources));
_COM_SMARTPTR_TYPEDEF(Assignments, __uuidof(Assignments));
_COM_SMARTPTR_TYPEDEF(ActualStartDrivers, __uuidof(ActualStartDrivers));
_COM_SMARTPTR_TYPEDEF(CalendarDrivers, __uuidof(CalendarDrivers));
_COM_SMARTPTR_TYPEDEF(OverAllocatedAssignments, __uuidof(OverAllocatedAssignments));
_COM_SMARTPTR_TYPEDEF(StartDriver, __uuidof(StartDriver));
_COM_SMARTPTR_TYPEDEF(Calendar, __uuidof(Calendar));
_COM_SMARTPTR_TYPEDEF(WeekDay, __uuidof(WeekDay));
_COM_SMARTPTR_TYPEDEF(WeekDays, __uuidof(WeekDays));
_COM_SMARTPTR_TYPEDEF(Period, __uuidof(Period));
_COM_SMARTPTR_TYPEDEF(Calendars, __uuidof(Calendars));
_COM_SMARTPTR_TYPEDEF(Exception, __uuidof(Exception));
_COM_SMARTPTR_TYPEDEF(Exceptions, __uuidof(Exceptions));
_COM_SMARTPTR_TYPEDEF(Years, __uuidof(Years));
_COM_SMARTPTR_TYPEDEF(Months, __uuidof(Months));
_COM_SMARTPTR_TYPEDEF(Year, __uuidof(Year));
_COM_SMARTPTR_TYPEDEF(Days, __uuidof(Days));
_COM_SMARTPTR_TYPEDEF(Month, __uuidof(Month));
_COM_SMARTPTR_TYPEDEF(Day, __uuidof(Day));
_COM_SMARTPTR_TYPEDEF(TaskGroups, __uuidof(TaskGroups));
_COM_SMARTPTR_TYPEDEF(ResourceGroups, __uuidof(ResourceGroups));
_COM_SMARTPTR_TYPEDEF(Group, __uuidof(Group));
_COM_SMARTPTR_TYPEDEF(GroupCriterion, __uuidof(GroupCriterion));
_COM_SMARTPTR_TYPEDEF(GroupCriteria, __uuidof(GroupCriteria));
_COM_SMARTPTR_TYPEDEF(Groups, __uuidof(Groups));
_COM_SMARTPTR_TYPEDEF(ViewsSingle, __uuidof(ViewsSingle));
_COM_SMARTPTR_TYPEDEF(ViewsCombination, __uuidof(ViewsCombination));
_COM_SMARTPTR_TYPEDEF(ViewSingle, __uuidof(ViewSingle));
_COM_SMARTPTR_TYPEDEF(ViewCombination, __uuidof(ViewCombination));
_COM_SMARTPTR_TYPEDEF(Tables, __uuidof(Tables));
_COM_SMARTPTR_TYPEDEF(Table, __uuidof(Table));
_COM_SMARTPTR_TYPEDEF(TableField, __uuidof(TableField));
_COM_SMARTPTR_TYPEDEF(TableFields, __uuidof(TableFields));
_COM_SMARTPTR_TYPEDEF(OutlineCode, __uuidof(OutlineCode));
_COM_SMARTPTR_TYPEDEF(OutlineCodes, __uuidof(OutlineCodes));
_COM_SMARTPTR_TYPEDEF(LookupTableEntry, __uuidof(LookupTableEntry));
_COM_SMARTPTR_TYPEDEF(LookupTable, __uuidof(LookupTable));
_COM_SMARTPTR_TYPEDEF(CodeMaskLevel, __uuidof(CodeMaskLevel));
_COM_SMARTPTR_TYPEDEF(CodeMask, __uuidof(CodeMask));
_COM_SMARTPTR_TYPEDEF(WorkWeek, __uuidof(WorkWeek));
_COM_SMARTPTR_TYPEDEF(WorkWeeks, __uuidof(WorkWeeks));
_COM_SMARTPTR_TYPEDEF(WorkWeekDay, __uuidof(WorkWeekDay));
_COM_SMARTPTR_TYPEDEF(WorkWeekDays, __uuidof(WorkWeekDays));
_COM_SMARTPTR_TYPEDEF(TaskGroups2, __uuidof(TaskGroups2));
_COM_SMARTPTR_TYPEDEF(ResourceGroups2, __uuidof(ResourceGroups2));
_COM_SMARTPTR_TYPEDEF(Group2, __uuidof(Group2));
_COM_SMARTPTR_TYPEDEF(GroupCriterion2, __uuidof(GroupCriterion2));
_COM_SMARTPTR_TYPEDEF(GroupCriteria2, __uuidof(GroupCriteria2));
_COM_SMARTPTR_TYPEDEF(Groups2, __uuidof(Groups2));
_COM_SMARTPTR_TYPEDEF(Reports, __uuidof(Reports));
_COM_SMARTPTR_TYPEDEF(Report, __uuidof(Report));
_COM_SMARTPTR_TYPEDEF(Shape, __uuidof(Shape));
_COM_SMARTPTR_TYPEDEF(Shapes, __uuidof(Shapes));
_COM_SMARTPTR_TYPEDEF(Chart, __uuidof(Chart));
_COM_SMARTPTR_TYPEDEF(ShapeRange, __uuidof(ShapeRange));

//
// Type library items
//

enum __declspec(uuid("c65ca460-670b-11cf-a59f-00aa004ccfe1"))
PjMonth
{
    pjJanuary = 1,
    pjFebruary = 2,
    pjMarch = 3,
    pjApril = 4,
    pjMay = 5,
    pjJune = 6,
    pjJuly = 7,
    pjAugust = 8,
    pjSeptember = 9,
    pjOctober = 10,
    pjNovember = 11,
    pjDecember = 12
};

enum __declspec(uuid("4c6a2d40-670c-11cf-a59f-00aa004ccfe1"))
PjAccrueAt
{
    pjStart = 1,
    pjEnd = 2,
    pjProrated = 3
};

enum __declspec(uuid("2f745300-6715-11cf-a5a1-00aa004ccfe1"))
PjDateFormat
{
    pjDateDefault = 255,
    pjDate_mm_dd_yy_hh_mmAM = 0,
    pjDate_mm_dd_yy = 1,
    pjDate_mmmm_dd_yyyy_hh_mmAM = 2,
    pjDate_mmmm_dd_yyyy = 3,
    pjDate_mmm_dd_hh_mmAM = 4,
    pjDate_mmm_dd_yyy = 5,
    pjDate_mmmm_dd = 6,
    pjDate_mmm_dd = 7,
    pjDate_ddd_mm_dd_yy_hh_mmAM = 8,
    pjDate_ddd_mm_dd_yy = 9,
    pjDate_ddd_mmm_dd_yyy = 10,
    pjDate_ddd_hh_mmAM = 11,
    pjDate_mm_dd = 12,
    pjDate_dd = 13,
    pjDate_hh_mmAM = 14,
    pjDate_ddd_mmm_dd = 15,
    pjDate_ddd_mm_dd = 16,
    pjDate_ddd_dd = 17,
    pjDate_Www_dd = 18,
    pjDate_Www_dd_yy_hh_mmAM = 19,
    pjDate_mm_dd_yyyy = 20
};

enum __declspec(uuid("f2e1a4e0-67f5-11cf-a5a5-00aa004ccfe1"))
PjConstraint
{
    pjASAP = 0,
    pjALAP = 1,
    pjFNET = 6,
    pjFNLT = 7,
    pjMFO = 3,
    pjMSO = 2,
    pjSNET = 4,
    pjSNLT = 5
};

enum __declspec(uuid("04f02fe0-8d9c-11cf-815e-00aa00ba2f2c"))
PjGridline
{
    pjBarRows = 1,
    pjCalendarDays = 0,
    pjCalendarTitleHorizontal = 3,
    pjCalendarTitleVertical = 2,
    pjCalendarWeeks = 1,
    pjDateBoxBottom = 5,
    pjDateBoxTop = 4,
    pjGanttRows = 0,
    pjSheetRows = 0,
    pjGanttCurrentDate = 4,
    pjGanttPageBreaks = 9,
    pjGanttProjectFinish = 11,
    pjGanttProjectStart = 10,
    pjGanttSheetColumns = 6,
    pjGanttSheetRows = 5,
    pjGanttTitleHorizontal = 8,
    pjGanttTitleVertical = 7,
    pjGanttStatusDate = 12,
    pjGraphCurrentDate = 3,
    pjGraphProjectFinish = 7,
    pjGraphProjectStart = 6,
    pjGraphTitleHorizontal = 5,
    pjGraphTitleVertical = 4,
    pjGraphStatusDate = 8,
    pjHorizontal = 2,
    pjMajorColumns = 2,
    pjMinorColumns = 3,
    pjMajorVertical = 0,
    pjMinorVertical = 1,
    pjSheetColumns = 1,
    pjSheetPageBreaks = 4,
    pjSheetTitleHorizontal = 3,
    pjSheetTitleVertical = 2,
    pjUsagePageBreaks = 6,
    pjUsageSheetColumns = 1,
    pjUsageSheetRows = 0,
    pjUsageTitleHorizontal = 3,
    pjUsageTitleVertical = 2,
    pjUsageRows = 5,
    pjUsageColumns = 4
};

enum __declspec(uuid("be02dfd0-8e58-11cf-982b-00aa00322803"))
PjBarSize
{
    pjBarSize6 = 6,
    pjBarSize8 = 8,
    pjBarSize10 = 10,
    pjBarSize12 = 12,
    pjBarSize14 = 14,
    pjBarSize18 = 18,
    pjBarSize24 = 24
};

enum __declspec(uuid("d329c3a0-8e5f-11cf-982b-00aa00322803"))
PjAlignment
{
    pjLeft = 0,
    pjCenter = 1,
    pjRight = 2
};

enum __declspec(uuid("79fb9edc-a5c2-11d2-8bfc-00c04f72f323"))
PjVerticalAlignment
{
    pjTop = 0,
    pjMiddle = 1,
    pjBottom = 2
};

enum __declspec(uuid("caea4740-9313-11cf-982d-00aa00322803"))
PjBarEndShape
{
    pjNoBarEndShape = 0,
    pjHouseUp = 1,
    pjHouseDown = 2,
    pjDiamond = 3,
    pjCircleDiamond = 13,
    pjTriangleUp = 4,
    pjTriangleDown = 5,
    pjTriangleRight = 6,
    pjTriangleLeft = 7,
    pjCircleTriangleUp = 15,
    pjCircleTriangleDown = 16,
    pjArrowUp = 8,
    pjArrowDown = 14,
    pjCircleArrowUp = 17,
    pjCircleArrowDown = 18,
    pjCaretDownTop = 9,
    pjCaretUpBottom = 10,
    pjLineShape = 11,
    pjSquare = 12,
    pjCircle = 19,
    pjStar = 20,
    pjLeftBracket = 21,
    pjRightBracket = 22,
    pjLeftFade = 23,
    pjRightFade = 24
};

enum __declspec(uuid("06de1740-8e61-11cf-982b-00aa00322803"))
PjBarItem
{
    pjBarNoncritical = 0,
    pjBarCritical = 1,
    pjBarSummary = 2,
    pjBarMilestone = 3,
    pjBarMarked = 5,
    pjBarHighlighted = 6,
    pjBarProjectSummary = 7,
    pjBarExternalTask = 8
};

enum __declspec(uuid("60f9edc0-8e61-11cf-982b-00aa00322803"))
PjBarShape
{
    pjNone = 0,
    pjRectangleBar = 1,
    pjRectangleTop = 2,
    pjRectangleMiddle = 3,
    pjRectangleBottom = 4,
    pjLineTop = 5,
    pjLineMiddle = 6,
    pjLineBottom = 7
};

enum __declspec(uuid("c939c770-8e61-11cf-982b-00aa00322803"))
PjBarType
{
    pjDashed = 2,
    pjFramed = 1,
    pjSolid = 0
};

enum __declspec(uuid("ad05c000-8e62-11cf-982b-00aa00322803"))
PjBorder
{
    pjNoBorder = 0,
    pjAroundEveryPage = 1,
    pjOutsidePages = 2
};

enum __declspec(uuid("3d856b00-8e63-11cf-982b-00aa00322803"))
PjCalculation
{
    pjAutomatic = -1,
    pjManual = 0
};

enum __declspec(uuid("5c5f74c0-8f34-11cf-982b-00aa00322803"))
PjCalendarBarType
{
    pjNormalBar = 0,
    pjLineBar = 1,
    pjNoBar = 2
};

enum __declspec(uuid("3d358b20-8f41-11cf-982b-00aa00322803"))
PjCalendarDateLabel
{
    pjCalendarLabelDay_mm_dd = 27,
    pjCalendarLabelDay_mm_dd_yy = 26,
    pjCalendarLabelDay_m_dd = 115,
    pjCalendarLabelDay_mmm_dd = 25,
    pjCalendarLabelDay_mmm_dd_yyy = 24,
    pjCalendarLabelDay_di = 20,
    pjCalendarLabelDay_di_mm_dd = 110,
    pjCalendarLabelDay_di_dd = 107,
    pjCalendarLabelDay_di_m_dd = 114,
    pjCalendarLabelDay_didd = 121,
    pjCalendarLabelDay_ddi = 119,
    pjCalendarLabelDay_ddi_mm_dd = 109,
    pjCalendarLabelDay_ddi_dd = 106,
    pjCalendarLabelDay_ddi_m_dd = 113,
    pjCalendarLabelDay_ddd = 19,
    pjCalendarLabelDay_ddd_mm_dd = 108,
    pjCalendarLabelDay_ddd_mm_dd_yy = 52,
    pjCalendarLabelDay_ddd_dd = 105,
    pjCalendarLabelDay_ddd_m_dd = 112,
    pjCalendarLabelDay_ddd_mmm_dd = 23,
    pjCalendarLabelDay_ddd_mmm_dd_yyy = 22,
    pjCalendarLabelDay_ddd_mmmm_dd = 111,
    pjCalendarLabelDay_dddd = 18,
    pjCalendarLabelDayFromEnd_dd = 54,
    pjCalendarLabelDayFromEnd_Ddd = 53,
    pjCalendarLabelDayFromEnd_Day_dd = 41,
    pjCalendarLabelDayFromStart_dd = 56,
    pjCalendarLabelDayFromStart_Ddd = 55,
    pjCalendarLabelDayFromStart_Day_dd = 40,
    pjCalendarLabelDayOfMonth_dd = 21,
    pjCalendarLabelDayOfYear_dd = 118,
    pjCalendarLabelDayOfYear_dd_yyyy = 117,
    pjCalendarLabelDayOfYear_dd_yyy = 116,
    pjNoDateFormat = 35,
    pjOverflowIndicator = 122
};

enum __declspec(uuid("502f6db0-8f42-11cf-982b-00aa00322803"))
PjCalendarShading
{
    pjBaseWorking = 0,
    pjBaseNonworking = 1,
    pjBaseNondefaultWorking = 2,
    pjResourceWorking = 3,
    pjResourceNonworking = 4,
    pjResourceNondefaultWorking = 5
};

enum __declspec(uuid("a496d170-8f45-11cf-982b-00aa00322803"))
PjColor
{
    pjBlack = 0,
    pjRed = 1,
    pjYellow = 2,
    pjLime = 3,
    pjAqua = 4,
    pjBlue = 5,
    pjFuchsia = 6,
    pjWhite = 7,
    pjMaroon = 8,
    pjGreen = 9,
    pjOlive = 10,
    pjNavy = 11,
    pjPurple = 12,
    pjTeal = 13,
    pjGray = 14,
    pjSilver = 15,
    pjColorAutomatic = 16
};

enum __declspec(uuid("322cc8f0-8f46-11cf-982b-00aa00322803"))
PjCreatePublisher
{
    pjPublishAll = 0,
    pjPictureOnly = 1
};

enum __declspec(uuid("7ee9bb70-8f46-11cf-982b-00aa00322803"))
PjCustomizeMailAction
{
    pjMailStartFields = 1,
    pjMailDefineField = 2,
    pjMailEndFields = 0
};

enum __declspec(uuid("a8002280-8f4b-11cf-982b-00aa00322803"))
PjDateLabel
{
    pjDay_mm_dd = 27,
    pjDay_mm_dd_yy = 26,
    pjDay_m_dd = 115,
    pjDay_mmm_dd = 25,
    pjDay_mmm_dd_yyy = 24,
    pjDay_di = 20,
    pjDay_di_mm_dd = 110,
    pjDay_di_dd = 107,
    pjDay_di_m_dd = 114,
    pjDay_didd = 121,
    pjDay_ddi = 119,
    pjDay_ddi_mm_dd = 109,
    pjDay_ddi_dd = 106,
    pjDay_ddi_m_dd = 113,
    pjDay_ddd = 19,
    pjDay_ddd_mm_dd = 108,
    pjDay_ddd_mm_dd_yy = 52,
    pjDay_ddd_dd = 105,
    pjDay_ddd_m_dd = 112,
    pjDay_ddd_mmm_dd = 23,
    pjDay_ddd_mmm_dd_yyy = 22,
    pjDay_ddd_mmmm_dd = 111,
    pjDay_dddd = 18,
    pjDayFromEnd_dd = 54,
    pjDayFromEnd_Ddd = 53,
    pjDayFromEnd_Day_dd = 41,
    pjDayFromStart_dd = 56,
    pjDayFromStart_Ddd = 55,
    pjDayFromStart_Day_dd = 40,
    pjDayOfMonth_dd = 21,
    pjDayOfYear_dd = 118,
    pjDayOfYear_dd_yyyy = 117,
    pjDayOfYear_dd_yyy = 116,
    pjHour_mm_dd_hhAM = 120,
    pjHour_hh = 32,
    pjHour_hh_mmAM = 30,
    pjHour_hhAM = 31,
    pjHour_mmm_dd_hhAM = 29,
    pjHour_ddd_mmm_dd_hhAM = 28,
    pjHourFromEnd_hh = 77,
    pjHourFromEnd_Hhh = 76,
    pjHourFromEnd_Hour_hh = 39,
    pjHourFromStart_hh = 79,
    pjHourFromStart_Hhh = 78,
    pjHourFromStart_Hour_hh = 38,
    pjMinute_hh_mmAM = 33,
    pjMinute_mm = 34,
    pjMinuteFromEnd_mm = 81,
    pjMinuteFromEnd_Mmm = 80,
    pjMinuteFromEnd_Minute_mm = 37,
    pjMinuteFromStart_mm = 83,
    pjMinuteFromStart_Mmm = 82,
    pjMinuteFromStart_Minute_mm = 36,
    pjMonth_mm = 57,
    pjMonth_mm_yy = 86,
    pjMonth_mm_yyy = 85,
    pjMonth_m = 11,
    pjMonth_mmm = 10,
    pjMonth_mmm_yyy = 8,
    pjMonth_mmmm = 9,
    pjMonth_mmmm_yyyy = 7,
    pjMonthFromEnd_mm = 59,
    pjMonthFromEnd_Mmm = 58,
    pjMonthFromEnd_Month_mm = 45,
    pjMonthFromStart_mm = 61,
    pjMonthFromStart_Mmm = 60,
    pjMonthFromStart_Month_mm = 44,
    pjQuarter_q = 62,
    pjQuarter_qQyy = 51,
    pjQuarter_qqq_Quarter = 2,
    pjQuarter_Qq = 6,
    pjQuarter_Qq_yyy = 4,
    pjQuarter_Qtr_q = 5,
    pjQuarter_Qtr_q_yyyy = 3,
    pjQuarterFromEnd_q = 64,
    pjQuarterFromEnd_Qq = 63,
    pjQuarterFromEnd_Quarter_q = 47,
    pjQuarterFromStart_q = 66,
    pjQuarterFromStart_Qq = 65,
    pjQuarterFromStart_Quarter_q = 46,
    pjWeek_mm_dd = 17,
    pjWeek_mm_dd_yy = 16,
    pjWeek_m_dd = 89,
    pjWeek_mmm_dd = 15,
    pjWeek_mmm_dd_yyy = 13,
    pjWeek_mmmm_dd = 14,
    pjWeek_mmmm_dd_yyyy = 12,
    pjWeek_di_mm_dd = 92,
    pjWeek_di_m_dd = 99,
    pjWeek_di_mmm_dd = 95,
    pjWeek_ddi_mm_dd = 91,
    pjWeek_ddi_m_dd = 98,
    pjWeek_ddi_mmm_dd = 94,
    pjWeek_ddd_mm_dd = 90,
    pjWeek_ddd_mm_dd_yy = 100,
    pjWeek_ddd_dd = 88,
    pjWeek_ddd_ww = 103,
    pjWeek_ddd_m_dd = 97,
    pjWeek_ddd_mmm_dd = 93,
    pjWeek_ddd_mmm_dd_yyy = 101,
    pjWeek_ddd_mmmm_dd = 96,
    pjWeek_ddd_mmmm_dd_yyy = 102,
    pjWeekDayOfMonth_dd = 87,
    pjWeekFromEnd_ww = 68,
    pjWeekFromEnd_Www = 67,
    pjWeekFromEnd_Week_ww = 43,
    pjWeekFromStart_ww = 70,
    pjWeekFromStart_Www = 69,
    pjWeekFromStart_Week_ww = 42,
    pjWeekNumber_dd_ww = 104,
    pjWeekNumber_ww = 50,
    pjYear_yyyy = 0,
    pjYear_yyy = 1,
    pjYear_yy = 75,
    pjYearFromEnd_yy = 72,
    pjYearFromEnd_Yyy = 71,
    pjYearFromEnd_Year_yy = 49,
    pjYearFromStart_yy = 74,
    pjYearFromStart_Yyy = 73,
    pjYearFromStart_Year_yy = 48,
    pjHalfYear_hhh_Half = 123,
    pjHalfYear_Hlf_h_yyyy = 124,
    pjHalfYear_Hlf_h = 125,
    pjHalfYear_Hh_yyy = 126,
    pjHalfYear_Hh = 127,
    pjHalfYear_h = 128,
    pjHalfYear_hHyy = 129,
    pjHalfYearFromStart_Half_h = 130,
    pjHalfYearFromStart_Hh = 131,
    pjHalfYearFromStart_h = 132,
    pjHalfYearFromEnd_Half_h = 133,
    pjHalfYearFromEnd_Hh = 134,
    pjHalfYearFromEnd_h = 135,
    pjThirdsOfMonths_dd = 136,
    pjThirdsOfMonths_ddd = 137,
    pjThirdsOfMonths_dddd = 138,
    pjThirdsOfMonths_mm_dd = 139,
    pjThirdsOfMonths_mm_ddd = 140,
    pjThirdsOfMonths_mmmm_dddd = 141,
    pjThirdsOfMonths_mmm_dd = 142,
    pjThirdsOfMonths_mmm_ddd = 143,
    pjThirdsOfMonths_mmmm_dd = 144,
    pjThirdsOfMonths_mm_dd_yy = 145,
    pjThirdsOfMonths_mm_ddd_yy = 146,
    pjThirdsOfMonths_mmm_dd_yy = 147,
    pjThirdsOfMonths_mmm_ddd_yy = 148,
    pjThirdsOfMonths_mmmm_dd_yyyy = 149,
    pjThirdsOfMonths_mmmm_dddd_yyyy = 150
};

enum __declspec(uuid("321ff2c0-8f4d-11cf-982b-00aa00322803"))
PjDateOrder
{
    pjDayMonthYear = 0,
    pjMonthDayYear = 1,
    pjYearMonthDay = 2
};

enum __declspec(uuid("29f575c0-919a-11cf-982c-00aa00322803"))
PjDayLabel
{
    pjDayLabelDay_di = 20,
    pjDayLabelDay_ddi = 119,
    pjDayLabelDay_ddd = 19,
    pjDayLabelDay_dddd = 18,
    pjDayLabelNoDateFormat = 35
};

enum __declspec(uuid("b05582c0-919a-11cf-982c-00aa00322803"))
PjDialog
{
    pjResourceAssignment = 4087
};

enum __declspec(uuid("6cc0ab34-3931-11d2-ae4c-00c04fb6f701"))
PjAssignmentField
{
    pjAssignmentUniqueID = 255852544,
    pjAssignmentTaskUniqueID = 255852545,
    pjAssignmentResourceUniqueID = 255852546,
    pjAssignmentTaskID = 255852547,
    pjAssignmentResourceID = 255852548,
    pjAssignmentTaskName = 255852549,
    pjAssignmentResourceName = 255852550,
    pjAssignmentAssignmentUnits = 255852551,
    pjAssignmentWork = 255852552,
    pjAssignmentOvertimeWork = 255852553,
    pjAssignmentActualWork = 255852554,
    pjAssignmentRegularWork = 255852555,
    pjAssignmentRemainingWork = 255852556,
    pjAssignmentActualOvertimeWork = 255852557,
    pjAssignmentRemainingOvertimeWork = 255852558,
    pjAssignmentBaselineWork = 255852560,
    pjAssignmentPeak = 255852563,
    pjAssignmentStart = 255852564,
    pjAssignmentFinish = 255852565,
    pjAssignmentActualStart = 255852566,
    pjAssignmentActualFinish = 255852567,
    pjAssignmentDelay = 255852569,
    pjAssignmentCost = 255852570,
    pjAssignmentOvertimeCost = 255852571,
    pjAssignmentActualCost = 255852572,
    pjAssignmentRemainingCost = 255852573,
    pjAssignmentActualOvertimeCost = 255852574,
    pjAssignmentRemainingOvertimeCost = 255852575,
    pjAssignmentBaselineCost = 255852576,
    pjAssignmentBCWS = 255852578,
    pjAssignmentBCWP = 255852579,
    pjAssignmentACWP = 255852580,
    pjAssignmentSV = 255852581,
    pjAssignmentCostVariance = 255852582,
    pjAssignmentWorkContour = 255852583,
    pjAssignmentPercentWorkComplete = 255852587,
    pjAssignmentProject = 255852588,
    pjAssignmentNotes = 255852615,
    pjAssignmentConfirmed = 255852616,
    pjAssignmentResponsePending = 255852617,
    pjAssignmentUpdateNeeded = 255852618,
    pjAssignmentTeamStatusPending = 255852619,
    pjAssignmentCostRateTable = 255852624,
    pjAssignmentText1 = 255852632,
    pjAssignmentText2 = 255852633,
    pjAssignmentText3 = 255852634,
    pjAssignmentText4 = 255852635,
    pjAssignmentText5 = 255852636,
    pjAssignmentText6 = 255852637,
    pjAssignmentText7 = 255852638,
    pjAssignmentText8 = 255852639,
    pjAssignmentText9 = 255852640,
    pjAssignmentText10 = 255852641,
    pjAssignmentStart1 = 255852642,
    pjAssignmentStart2 = 255852643,
    pjAssignmentStart3 = 255852644,
    pjAssignmentStart4 = 255852645,
    pjAssignmentStart5 = 255852646,
    pjAssignmentFinish1 = 255852647,
    pjAssignmentFinish2 = 255852648,
    pjAssignmentFinish3 = 255852649,
    pjAssignmentFinish4 = 255852650,
    pjAssignmentFinish5 = 255852651,
    pjAssignmentNumber1 = 255852652,
    pjAssignmentNumber2 = 255852653,
    pjAssignmentNumber3 = 255852654,
    pjAssignmentNumber4 = 255852655,
    pjAssignmentNumber5 = 255852656,
    pjAssignmentDuration1 = 255852657,
    pjAssignmentDuration2 = 255852658,
    pjAssignmentDuration3 = 255852659,
    pjAssignmentCost1 = 255852663,
    pjAssignmentCost2 = 255852664,
    pjAssignmentCost3 = 255852665,
    pjAssignmentFlag10 = 255852666,
    pjAssignmentFlag1 = 255852667,
    pjAssignmentFlag2 = 255852668,
    pjAssignmentFlag3 = 255852669,
    pjAssignmentFlag4 = 255852670,
    pjAssignmentFlag5 = 255852671,
    pjAssignmentFlag6 = 255852672,
    pjAssignmentFlag7 = 255852673,
    pjAssignmentFlag8 = 255852674,
    pjAssignmentFlag9 = 255852675,
    pjAssignmentLinkedFields = 255852676,
    pjAssignmentOverallocated = 255852679,
    pjAssignmentTaskSummaryName = 255852686,
    pjAssignmentLevelingDelay = 255852689,
    pjAssignmentBaselineStart = 255852690,
    pjAssignmentBaselineFinish = 255852691,
    pjAssignmentHyperlink = 255852696,
    pjAssignmentHyperlinkAddress = 255852697,
    pjAssignmentHyperlinkSubAddress = 255852698,
    pjAssignmentHyperlinkHREF = 255852699,
    pjAssignmentCost4 = 255852703,
    pjAssignmentCost5 = 255852704,
    pjAssignmentCost6 = 255852705,
    pjAssignmentCost7 = 255852706,
    pjAssignmentCost8 = 255852707,
    pjAssignmentCost9 = 255852708,
    pjAssignmentCost10 = 255852709,
    pjAssignmentDate1 = 255852710,
    pjAssignmentDate2 = 255852711,
    pjAssignmentDate3 = 255852712,
    pjAssignmentDate4 = 255852713,
    pjAssignmentDate5 = 255852714,
    pjAssignmentDate6 = 255852715,
    pjAssignmentDate7 = 255852716,
    pjAssignmentDate8 = 255852717,
    pjAssignmentDate9 = 255852718,
    pjAssignmentDate10 = 255852719,
    pjAssignmentDuration4 = 255852720,
    pjAssignmentDuration5 = 255852721,
    pjAssignmentDuration6 = 255852722,
    pjAssignmentDuration7 = 255852723,
    pjAssignmentDuration8 = 255852724,
    pjAssignmentDuration9 = 255852725,
    pjAssignmentDuration10 = 255852726,
    pjAssignmentFinish6 = 255852727,
    pjAssignmentFinish7 = 255852728,
    pjAssignmentFinish8 = 255852729,
    pjAssignmentFinish9 = 255852730,
    pjAssignmentFinish10 = 255852731,
    pjAssignmentFlag11 = 255852732,
    pjAssignmentFlag12 = 255852733,
    pjAssignmentFlag13 = 255852734,
    pjAssignmentFlag14 = 255852735,
    pjAssignmentFlag15 = 255852736,
    pjAssignmentFlag16 = 255852737,
    pjAssignmentFlag17 = 255852738,
    pjAssignmentFlag18 = 255852739,
    pjAssignmentFlag19 = 255852740,
    pjAssignmentFlag20 = 255852741,
    pjAssignmentNumber6 = 255852742,
    pjAssignmentNumber7 = 255852743,
    pjAssignmentNumber8 = 255852744,
    pjAssignmentNumber9 = 255852745,
    pjAssignmentNumber10 = 255852746,
    pjAssignmentNumber11 = 255852747,
    pjAssignmentNumber12 = 255852748,
    pjAssignmentNumber13 = 255852749,
    pjAssignmentNumber14 = 255852750,
    pjAssignmentNumber15 = 255852751,
    pjAssignmentNumber16 = 255852752,
    pjAssignmentNumber17 = 255852753,
    pjAssignmentNumber18 = 255852754,
    pjAssignmentNumber19 = 255852755,
    pjAssignmentNumber20 = 255852756,
    pjAssignmentStart6 = 255852757,
    pjAssignmentStart7 = 255852758,
    pjAssignmentStart8 = 255852759,
    pjAssignmentStart9 = 255852760,
    pjAssignmentStart10 = 255852761,
    pjAssignmentText11 = 255852762,
    pjAssignmentText12 = 255852763,
    pjAssignmentText13 = 255852764,
    pjAssignmentText14 = 255852765,
    pjAssignmentText15 = 255852766,
    pjAssignmentText16 = 255852767,
    pjAssignmentText17 = 255852768,
    pjAssignmentText18 = 255852769,
    pjAssignmentText19 = 255852770,
    pjAssignmentText20 = 255852771,
    pjAssignmentText21 = 255852772,
    pjAssignmentText22 = 255852773,
    pjAssignmentText23 = 255852774,
    pjAssignmentText24 = 255852775,
    pjAssignmentText25 = 255852776,
    pjAssignmentText26 = 255852777,
    pjAssignmentText27 = 255852778,
    pjAssignmentText28 = 255852779,
    pjAssignmentText29 = 255852780,
    pjAssignmentText30 = 255852781,
    pjAssignmentIndex = 255852790,
    pjAssignmentCV = 255852791,
    pjAssignmentWorkVariance = 255852792,
    pjAssignmentStartVariance = 255852806,
    pjAssignmentFinishVariance = 255852807,
    pjAssignmentVAC = 255852815,
    pjAssignmentFixedMaterialAssignment = 255852819,
    pjAssignmentResourceType = 255852820,
    pjAssignmentHyperlinkScreenTip = 255852823,
    pjAssignmentWBS = 255852830,
    pjAssignmentBaseline1Work = 255852833,
    pjAssignmentBaseline1Cost = 255852834,
    pjAssignmentBaseline1Start = 255852839,
    pjAssignmentBaseline1Finish = 255852840,
    pjAssignmentBaseline2Work = 255852842,
    pjAssignmentBaseline2Cost = 255852843,
    pjAssignmentBaseline2Start = 255852848,
    pjAssignmentBaseline2Finish = 255852849,
    pjAssignmentBaseline3Work = 255852851,
    pjAssignmentBaseline3Cost = 255852852,
    pjAssignmentBaseline3Start = 255852857,
    pjAssignmentBaseline3Finish = 255852858,
    pjAssignmentBaseline4Work = 255852860,
    pjAssignmentBaseline4Cost = 255852861,
    pjAssignmentBaseline4Start = 255852866,
    pjAssignmentBaseline4Finish = 255852867,
    pjAssignmentBaseline5Work = 255852869,
    pjAssignmentBaseline5Cost = 255852870,
    pjAssignmentBaseline5Start = 255852875,
    pjAssignmentBaseline5Finish = 255852876,
    pjAssignmentBaseline6Work = 255852878,
    pjAssignmentBaseline6Cost = 255852879,
    pjAssignmentBaseline6Start = 255852884,
    pjAssignmentBaseline6Finish = 255852885,
    pjAssignmentBaseline7Work = 255852887,
    pjAssignmentBaseline7Cost = 255852888,
    pjAssignmentBaseline7Start = 255852893,
    pjAssignmentBaseline7Finish = 255852894,
    pjAssignmentBaseline8Work = 255852896,
    pjAssignmentBaseline8Cost = 255852897,
    pjAssignmentBaseline8Start = 255852902,
    pjAssignmentBaseline8Finish = 255852903,
    pjAssignmentBaseline9Work = 255852905,
    pjAssignmentBaseline9Cost = 255852906,
    pjAssignmentBaseline9Start = 255852911,
    pjAssignmentBaseline9Finish = 255852912,
    pjAssignmentBaseline10Work = 255852914,
    pjAssignmentBaseline10Cost = 255852915,
    pjAssignmentBaseline10Start = 255852920,
    pjAssignmentBaseline10Finish = 255852921,
    pjAssignmentTaskOutlineNumber = 255852923,
    pjAssignmentEnterpriseCost1 = 255852925,
    pjAssignmentEnterpriseCost2 = 255852926,
    pjAssignmentEnterpriseCost3 = 255852927,
    pjAssignmentEnterpriseCost4 = 255852928,
    pjAssignmentEnterpriseCost5 = 255852929,
    pjAssignmentEnterpriseCost6 = 255852930,
    pjAssignmentEnterpriseCost7 = 255852931,
    pjAssignmentEnterpriseCost8 = 255852932,
    pjAssignmentEnterpriseCost9 = 255852933,
    pjAssignmentEnterpriseCost10 = 255852934,
    pjAssignmentEnterpriseDate1 = 255852935,
    pjAssignmentEnterpriseDate2 = 255852936,
    pjAssignmentEnterpriseDate3 = 255852937,
    pjAssignmentEnterpriseDate4 = 255852938,
    pjAssignmentEnterpriseDate5 = 255852939,
    pjAssignmentEnterpriseDate6 = 255852940,
    pjAssignmentEnterpriseDate7 = 255852941,
    pjAssignmentEnterpriseDate8 = 255852942,
    pjAssignmentEnterpriseDate9 = 255852943,
    pjAssignmentEnterpriseDate10 = 255852944,
    pjAssignmentEnterpriseDate11 = 255852945,
    pjAssignmentEnterpriseDate12 = 255852946,
    pjAssignmentEnterpriseDate13 = 255852947,
    pjAssignmentEnterpriseDate14 = 255852948,
    pjAssignmentEnterpriseDate15 = 255852949,
    pjAssignmentEnterpriseDate16 = 255852950,
    pjAssignmentEnterpriseDate17 = 255852951,
    pjAssignmentEnterpriseDate18 = 255852952,
    pjAssignmentEnterpriseDate19 = 255852953,
    pjAssignmentEnterpriseDate20 = 255852954,
    pjAssignmentEnterpriseDate21 = 255852955,
    pjAssignmentEnterpriseDate22 = 255852956,
    pjAssignmentEnterpriseDate23 = 255852957,
    pjAssignmentEnterpriseDate24 = 255852958,
    pjAssignmentEnterpriseDate25 = 255852959,
    pjAssignmentEnterpriseDate26 = 255852960,
    pjAssignmentEnterpriseDate27 = 255852961,
    pjAssignmentEnterpriseDate28 = 255852962,
    pjAssignmentEnterpriseDate29 = 255852963,
    pjAssignmentEnterpriseDate30 = 255852964,
    pjAssignmentEnterpriseDuration1 = 255852965,
    pjAssignmentEnterpriseDuration2 = 255852966,
    pjAssignmentEnterpriseDuration3 = 255852967,
    pjAssignmentEnterpriseDuration4 = 255852968,
    pjAssignmentEnterpriseDuration5 = 255852969,
    pjAssignmentEnterpriseDuration6 = 255852970,
    pjAssignmentEnterpriseDuration7 = 255852971,
    pjAssignmentEnterpriseDuration8 = 255852972,
    pjAssignmentEnterpriseDuration9 = 255852973,
    pjAssignmentEnterpriseDuration10 = 255852974,
    pjAssignmentEnterpriseFlag1 = 255852985,
    pjAssignmentEnterpriseFlag2 = 255852986,
    pjAssignmentEnterpriseFlag3 = 255852987,
    pjAssignmentEnterpriseFlag4 = 255852988,
    pjAssignmentEnterpriseFlag5 = 255852989,
    pjAssignmentEnterpriseFlag6 = 255852990,
    pjAssignmentEnterpriseFlag7 = 255852991,
    pjAssignmentEnterpriseFlag8 = 255852992,
    pjAssignmentEnterpriseFlag9 = 255852993,
    pjAssignmentEnterpriseFlag10 = 255852994,
    pjAssignmentEnterpriseFlag11 = 255852995,
    pjAssignmentEnterpriseFlag12 = 255852996,
    pjAssignmentEnterpriseFlag13 = 255852997,
    pjAssignmentEnterpriseFlag14 = 255852998,
    pjAssignmentEnterpriseFlag15 = 255852999,
    pjAssignmentEnterpriseFlag16 = 255853000,
    pjAssignmentEnterpriseFlag17 = 255853001,
    pjAssignmentEnterpriseFlag18 = 255853002,
    pjAssignmentEnterpriseFlag19 = 255853003,
    pjAssignmentEnterpriseFlag20 = 255853004,
    pjAssignmentEnterpriseNumber1 = 255853005,
    pjAssignmentEnterpriseNumber2 = 255853006,
    pjAssignmentEnterpriseNumber3 = 255853007,
    pjAssignmentEnterpriseNumber4 = 255853008,
    pjAssignmentEnterpriseNumber5 = 255853009,
    pjAssignmentEnterpriseNumber6 = 255853010,
    pjAssignmentEnterpriseNumber7 = 255853011,
    pjAssignmentEnterpriseNumber8 = 255853012,
    pjAssignmentEnterpriseNumber9 = 255853013,
    pjAssignmentEnterpriseNumber10 = 255853014,
    pjAssignmentEnterpriseNumber11 = 255853015,
    pjAssignmentEnterpriseNumber12 = 255853016,
    pjAssignmentEnterpriseNumber13 = 255853017,
    pjAssignmentEnterpriseNumber14 = 255853018,
    pjAssignmentEnterpriseNumber15 = 255853019,
    pjAssignmentEnterpriseNumber16 = 255853020,
    pjAssignmentEnterpriseNumber17 = 255853021,
    pjAssignmentEnterpriseNumber18 = 255853022,
    pjAssignmentEnterpriseNumber19 = 255853023,
    pjAssignmentEnterpriseNumber20 = 255853024,
    pjAssignmentEnterpriseNumber21 = 255853025,
    pjAssignmentEnterpriseNumber22 = 255853026,
    pjAssignmentEnterpriseNumber23 = 255853027,
    pjAssignmentEnterpriseNumber24 = 255853028,
    pjAssignmentEnterpriseNumber25 = 255853029,
    pjAssignmentEnterpriseNumber26 = 255853030,
    pjAssignmentEnterpriseNumber27 = 255853031,
    pjAssignmentEnterpriseNumber28 = 255853032,
    pjAssignmentEnterpriseNumber29 = 255853033,
    pjAssignmentEnterpriseNumber30 = 255853034,
    pjAssignmentEnterpriseNumber31 = 255853035,
    pjAssignmentEnterpriseNumber32 = 255853036,
    pjAssignmentEnterpriseNumber33 = 255853037,
    pjAssignmentEnterpriseNumber34 = 255853038,
    pjAssignmentEnterpriseNumber35 = 255853039,
    pjAssignmentEnterpriseNumber36 = 255853040,
    pjAssignmentEnterpriseNumber37 = 255853041,
    pjAssignmentEnterpriseNumber38 = 255853042,
    pjAssignmentEnterpriseNumber39 = 255853043,
    pjAssignmentEnterpriseNumber40 = 255853044,
    pjAssignmentEnterpriseText1 = 255853045,
    pjAssignmentEnterpriseText2 = 255853046,
    pjAssignmentEnterpriseText3 = 255853047,
    pjAssignmentEnterpriseText4 = 255853048,
    pjAssignmentEnterpriseText5 = 255853049,
    pjAssignmentEnterpriseText6 = 255853050,
    pjAssignmentEnterpriseText7 = 255853051,
    pjAssignmentEnterpriseText8 = 255853052,
    pjAssignmentEnterpriseText9 = 255853053,
    pjAssignmentEnterpriseText10 = 255853054,
    pjAssignmentEnterpriseText11 = 255853055,
    pjAssignmentEnterpriseText12 = 255853056,
    pjAssignmentEnterpriseText13 = 255853057,
    pjAssignmentEnterpriseText14 = 255853058,
    pjAssignmentEnterpriseText15 = 255853059,
    pjAssignmentEnterpriseText16 = 255853060,
    pjAssignmentEnterpriseText17 = 255853061,
    pjAssignmentEnterpriseText18 = 255853062,
    pjAssignmentEnterpriseText19 = 255853063,
    pjAssignmentEnterpriseText20 = 255853064,
    pjAssignmentEnterpriseText21 = 255853065,
    pjAssignmentEnterpriseText22 = 255853066,
    pjAssignmentEnterpriseText23 = 255853067,
    pjAssignmentEnterpriseText24 = 255853068,
    pjAssignmentEnterpriseText25 = 255853069,
    pjAssignmentEnterpriseText26 = 255853070,
    pjAssignmentEnterpriseText27 = 255853071,
    pjAssignmentEnterpriseText28 = 255853072,
    pjAssignmentEnterpriseText29 = 255853073,
    pjAssignmentEnterpriseText30 = 255853074,
    pjAssignmentEnterpriseText31 = 255853075,
    pjAssignmentEnterpriseText32 = 255853076,
    pjAssignmentEnterpriseText33 = 255853077,
    pjAssignmentEnterpriseText34 = 255853078,
    pjAssignmentEnterpriseText35 = 255853079,
    pjAssignmentEnterpriseText36 = 255853080,
    pjAssignmentEnterpriseText37 = 255853081,
    pjAssignmentEnterpriseText38 = 255853082,
    pjAssignmentEnterpriseText39 = 255853083,
    pjAssignmentEnterpriseText40 = 255853084,
    pjAssignmentEnterpriseResourceOutlineCode1 = 255853089,
    pjAssignmentEnterpriseResourceOutlineCode2 = 255853090,
    pjAssignmentEnterpriseResourceOutlineCode3 = 255853091,
    pjAssignmentEnterpriseResourceOutlineCode4 = 255853092,
    pjAssignmentEnterpriseResourceOutlineCode5 = 255853093,
    pjAssignmentEnterpriseResourceOutlineCode6 = 255853094,
    pjAssignmentEnterpriseResourceOutlineCode7 = 255853095,
    pjAssignmentEnterpriseResourceOutlineCode8 = 255853096,
    pjAssignmentEnterpriseResourceOutlineCode9 = 255853097,
    pjAssignmentEnterpriseResourceOutlineCode10 = 255853098,
    pjAssignmentEnterpriseResourceOutlineCode11 = 255853099,
    pjAssignmentEnterpriseResourceOutlineCode12 = 255853100,
    pjAssignmentEnterpriseResourceOutlineCode13 = 255853101,
    pjAssignmentEnterpriseResourceOutlineCode14 = 255853102,
    pjAssignmentEnterpriseResourceOutlineCode15 = 255853103,
    pjAssignmentEnterpriseResourceOutlineCode16 = 255853104,
    pjAssignmentEnterpriseResourceOutlineCode17 = 255853105,
    pjAssignmentEnterpriseResourceOutlineCode18 = 255853106,
    pjAssignmentEnterpriseResourceOutlineCode19 = 255853107,
    pjAssignmentEnterpriseResourceOutlineCode20 = 255853108,
    pjAssignmentEnterpriseResourceOutlineCode21 = 255853109,
    pjAssignmentEnterpriseResourceOutlineCode22 = 255853110,
    pjAssignmentEnterpriseResourceOutlineCode23 = 255853111,
    pjAssignmentEnterpriseResourceOutlineCode24 = 255853112,
    pjAssignmentEnterpriseResourceOutlineCode25 = 255853113,
    pjAssignmentEnterpriseResourceOutlineCode26 = 255853114,
    pjAssignmentEnterpriseResourceOutlineCode27 = 255853115,
    pjAssignmentEnterpriseResourceOutlineCode28 = 255853116,
    pjAssignmentEnterpriseResourceOutlineCode29 = 255853117,
    pjAssignmentEnterpriseResourceRBS = 255853118,
    pjAssignmentResourceRequestType = 255853149,
    pjAssignmentEnterpriseTeamMember = 255853151,
    pjAssignmentEnterpriseResourceMultiValue20 = 255853154,
    pjAssignmentEnterpriseResourceMultiValue21 = 255853156,
    pjAssignmentEnterpriseResourceMultiValue22 = 255853158,
    pjAssignmentEnterpriseResourceMultiValue23 = 255853160,
    pjAssignmentEnterpriseResourceMultiValue24 = 255853162,
    pjAssignmentEnterpriseResourceMultiValue25 = 255853164,
    pjAssignmentEnterpriseResourceMultiValue26 = 255853166,
    pjAssignmentEnterpriseResourceMultiValue27 = 255853168,
    pjAssignmentEnterpriseResourceMultiValue28 = 255853170,
    pjAssignmentEnterpriseResourceMultiValue29 = 255853172,
    pjAssignmentActualWorkProtected = 255853174,
    pjAssignmentActualOvtWorkProtected = 255853175,
    pjAssignmentCreated = 255853178,
    pjAssignmentGuid = 255853180,
    pjAssignmentTaskGuid = 255853181,
    pjAssignmentResourceGuid = 255853182,
    pjAssignmentSummary = 255853190,
    pjAssignmentOwner = 255853212,
    pjAssignmentBudgetWork = 255853213,
    pjAssignmentBudgetCost = 255853214,
    pjAssignmentBaselineBudgetWork = 255853217,
    pjAssignmentBaselineBudgetCost = 255853218,
    pjAssignmentBaseline1BudgetWork = 255853221,
    pjAssignmentBaseline1BudgetCost = 255853222,
    pjAssignmentBaseline2BudgetWork = 255853225,
    pjAssignmentBaseline2BudgetCost = 255853226,
    pjAssignmentBaseline3BudgetWork = 255853229,
    pjAssignmentBaseline3BudgetCost = 255853230,
    pjAssignmentBaseline4BudgetWork = 255853233,
    pjAssignmentBaseline4BudgetCost = 255853234,
    pjAssignmentBaseline5BudgetWork = 255853237,
    pjAssignmentBaseline5BudgetCost = 255853238,
    pjAssignmentBaseline6BudgetWork = 255853241,
    pjAssignmentBaseline6BudgetCost = 255853242,
    pjAssignmentBaseline7BudgetWork = 255853245,
    pjAssignmentBaseline7BudgetCost = 255853246,
    pjAssignmentBaseline8BudgetWork = 255853249,
    pjAssignmentBaseline8BudgetCost = 255853250,
    pjAssignmentBaseline9BudgetWork = 255853253,
    pjAssignmentBaseline9BudgetCost = 255853254,
    pjAssignmentBaseline10BudgetWork = 255853257,
    pjAssignmentBaseline10BudgetCost = 255853258
};

enum __declspec(uuid("dd3d3a50-919a-11cf-982c-00aa00322803"))
PjField
{
    pjTaskWork = 188743680,
    pjTaskBaselineWork = 188743681,
    pjTaskActualWork = 188743682,
    pjTaskWorkVariance = 188743683,
    pjTaskRemainingWork = 188743684,
    pjTaskCost = 188743685,
    pjTaskBaselineCost = 188743686,
    pjTaskActualCost = 188743687,
    pjTaskFixedCost = 188743688,
    pjTaskCostVariance = 188743689,
    pjTaskRemainingCost = 188743690,
    pjTaskBCWP = 188743691,
    pjTaskBCWS = 188743692,
    pjTaskSV = 188743693,
    pjTaskName = 188743694,
    pjTaskNotes = 188743695,
    pjTaskWBS = 188743696,
    pjTaskConstraintType = 188743697,
    pjTaskConstraintDate = 188743698,
    pjTaskCritical = 188743699,
    pjTaskLevelDelay = 188743700,
    pjTaskFreeSlack = 188743701,
    pjTaskTotalSlack = 188743702,
    pjTaskID = 188743703,
    pjTaskMilestone = 188743704,
    pjTaskPriority = 188743705,
    pjTaskSubproject = 188743706,
    pjTaskBaselineDuration = 188743707,
    pjTaskActualDuration = 188743708,
    pjTaskDuration = 188743709,
    pjTaskDurationVariance = 188743710,
    pjTaskRemainingDuration = 188743711,
    pjTaskPercentComplete = 188743712,
    pjTaskPercentWorkComplete = 188743713,
    pjTaskFixedDuration = 188743714,
    pjTaskStart = 188743715,
    pjTaskFinish = 188743716,
    pjTaskEarlyStart = 188743717,
    pjTaskEarlyFinish = 188743718,
    pjTaskLateStart = 188743719,
    pjTaskLateFinish = 188743720,
    pjTaskActualStart = 188743721,
    pjTaskActualFinish = 188743722,
    pjTaskBaselineStart = 188743723,
    pjTaskBaselineFinish = 188743724,
    pjTaskStartVariance = 188743725,
    pjTaskFinishVariance = 188743726,
    pjTaskPredecessors = 188743727,
    pjTaskSuccessors = 188743728,
    pjTaskResourceNames = 188743729,
    pjTaskResourceInitials = 188743730,
    pjTaskText1 = 188743731,
    pjTaskStart1 = 188743732,
    pjTaskFinish1 = 188743733,
    pjTaskText2 = 188743734,
    pjTaskStart2 = 188743735,
    pjTaskFinish2 = 188743736,
    pjTaskText3 = 188743737,
    pjTaskStart3 = 188743738,
    pjTaskFinish3 = 188743739,
    pjTaskText4 = 188743740,
    pjTaskStart4 = 188743741,
    pjTaskFinish4 = 188743742,
    pjTaskText5 = 188743743,
    pjTaskStart5 = 188743744,
    pjTaskFinish5 = 188743745,
    pjTaskText6 = 188743746,
    pjTaskText7 = 188743747,
    pjTaskText8 = 188743748,
    pjTaskText9 = 188743749,
    pjTaskText10 = 188743750,
    pjTaskMarked = 188743751,
    pjTaskFlag1 = 188743752,
    pjTaskFlag2 = 188743753,
    pjTaskFlag3 = 188743754,
    pjTaskFlag4 = 188743755,
    pjTaskFlag5 = 188743756,
    pjTaskFlag6 = 188743757,
    pjTaskFlag7 = 188743758,
    pjTaskFlag8 = 188743759,
    pjTaskFlag9 = 188743760,
    pjTaskFlag10 = 188743761,
    pjTaskRollup = 188743762,
    pjTaskCV = 188743763,
    pjTaskProject = 188743764,
    pjTaskOutlineLevel = 188743765,
    pjTaskUniqueID = 188743766,
    pjTaskNumber1 = 188743767,
    pjTaskNumber2 = 188743768,
    pjTaskNumber3 = 188743769,
    pjTaskNumber4 = 188743770,
    pjTaskNumber5 = 188743771,
    pjTaskSummary = 188743772,
    pjTaskCreated = 188743773,
    pjTaskSheetNotes = 188743774,
    pjTaskUniquePredecessors = 188743775,
    pjTaskUniqueSuccessors = 188743776,
    pjTaskObjects = 188743777,
    pjTaskLinkedFields = 188743778,
    pjTaskResume = 188743779,
    pjTaskStop = 188743780,
    pjTaskResumeNoEarlierThan = 188743781,
    pjTaskOutlineNumber = 188743782,
    pjTaskDuration1 = 188743783,
    pjTaskDuration2 = 188743784,
    pjTaskDuration3 = 188743785,
    pjTaskCost1 = 188743786,
    pjTaskCost2 = 188743787,
    pjTaskCost3 = 188743788,
    pjTaskHideBar = 188743789,
    pjTaskConfirmed = 188743790,
    pjTaskUpdateNeeded = 188743791,
    pjTaskContact = 188743792,
    pjTaskResourceGroup = 188743793,
    pjTaskACWP = 188743800,
    pjTaskType = 188743808,
    pjTaskRecurring = 188743809,
    pjTaskEffortDriven = 188743812,
    pjTaskParentTask = 188743815,
    pjTaskOvertimeWork = 188743843,
    pjTaskActualOvertimeWork = 188743844,
    pjTaskRemainingOvertimeWork = 188743845,
    pjTaskRegularWork = 188743846,
    pjTaskOvertimeCost = 188743848,
    pjTaskActualOvertimeCost = 188743849,
    pjTaskRemainingOvertimeCost = 188743850,
    pjTaskFixedCostAccrual = 188743880,
    pjTaskIndicators = 188743885,
    pjTaskHyperlink = 188743897,
    pjTaskHyperlinkAddress = 188743898,
    pjTaskHyperlinkSubAddress = 188743899,
    pjTaskHyperlinkHref = 188743900,
    pjTaskIsAssignment = 188743904,
    pjTaskOverallocated = 188743905,
    pjTaskExternalTask = 188743912,
    pjTaskSubprojectReadOnly = 188743926,
    pjTaskResponsePending = 188743930,
    pjTaskTeamStatusPending = 188743931,
    pjTaskLevelCanSplit = 188743932,
    pjTaskLevelAssignments = 188743933,
    pjTaskWorkContour = 188743936,
    pjTaskCost4 = 188743938,
    pjTaskCost5 = 188743939,
    pjTaskCost6 = 188743940,
    pjTaskCost7 = 188743941,
    pjTaskCost8 = 188743942,
    pjTaskCost9 = 188743943,
    pjTaskCost10 = 188743944,
    pjTaskDate1 = 188743945,
    pjTaskDate2 = 188743946,
    pjTaskDate3 = 188743947,
    pjTaskDate4 = 188743948,
    pjTaskDate5 = 188743949,
    pjTaskDate6 = 188743950,
    pjTaskDate7 = 188743951,
    pjTaskDate8 = 188743952,
    pjTaskDate9 = 188743953,
    pjTaskDate10 = 188743954,
    pjTaskDuration4 = 188743955,
    pjTaskDuration5 = 188743956,
    pjTaskDuration6 = 188743957,
    pjTaskDuration7 = 188743958,
    pjTaskDuration8 = 188743959,
    pjTaskDuration9 = 188743960,
    pjTaskDuration10 = 188743961,
    pjTaskStart6 = 188743962,
    pjTaskFinish6 = 188743963,
    pjTaskStart7 = 188743964,
    pjTaskFinish7 = 188743965,
    pjTaskStart8 = 188743966,
    pjTaskFinish8 = 188743967,
    pjTaskStart9 = 188743968,
    pjTaskFinish9 = 188743969,
    pjTaskStart10 = 188743970,
    pjTaskFinish10 = 188743971,
    pjTaskFlag11 = 188743972,
    pjTaskFlag12 = 188743973,
    pjTaskFlag13 = 188743974,
    pjTaskFlag14 = 188743975,
    pjTaskFlag15 = 188743976,
    pjTaskFlag16 = 188743977,
    pjTaskFlag17 = 188743978,
    pjTaskFlag18 = 188743979,
    pjTaskFlag19 = 188743980,
    pjTaskFlag20 = 188743981,
    pjTaskNumber6 = 188743982,
    pjTaskNumber7 = 188743983,
    pjTaskNumber8 = 188743984,
    pjTaskNumber9 = 188743985,
    pjTaskNumber10 = 188743986,
    pjTaskNumber11 = 188743987,
    pjTaskNumber12 = 188743988,
    pjTaskNumber13 = 188743989,
    pjTaskNumber14 = 188743990,
    pjTaskNumber15 = 188743991,
    pjTaskNumber16 = 188743992,
    pjTaskNumber17 = 188743993,
    pjTaskNumber18 = 188743994,
    pjTaskNumber19 = 188743995,
    pjTaskNumber20 = 188743996,
    pjTaskText11 = 188743997,
    pjTaskText12 = 188743998,
    pjTaskText13 = 188743999,
    pjTaskText14 = 188744000,
    pjTaskText15 = 188744001,
    pjTaskText16 = 188744002,
    pjTaskText17 = 188744003,
    pjTaskText18 = 188744004,
    pjTaskText19 = 188744005,
    pjTaskText20 = 188744006,
    pjTaskText21 = 188744007,
    pjTaskText22 = 188744008,
    pjTaskText23 = 188744009,
    pjTaskText24 = 188744010,
    pjTaskText25 = 188744011,
    pjTaskText26 = 188744012,
    pjTaskText27 = 188744013,
    pjTaskText28 = 188744014,
    pjTaskText29 = 188744015,
    pjTaskText30 = 188744016,
    pjTaskResourcePhonetics = 188744029,
    pjTaskIndex = 188744040,
    pjTaskAssignmentDelay = 188744046,
    pjTaskAssignmentUnits = 188744047,
    pjTaskCostRateTable = 188744048,
    pjTaskPreleveledStart = 188744049,
    pjTaskPreleveledFinish = 188744050,
    pjTaskEstimated = 188744076,
    pjTaskIgnoreResourceCalendar = 188744079,
    pjTaskCalendar = 188744082,
    pjTaskDuration1Estimated = 188744083,
    pjTaskDuration2Estimated = 188744084,
    pjTaskDuration3Estimated = 188744085,
    pjTaskDuration4Estimated = 188744086,
    pjTaskDuration5Estimated = 188744087,
    pjTaskDuration6Estimated = 188744088,
    pjTaskDuration7Estimated = 188744089,
    pjTaskDuration8Estimated = 188744090,
    pjTaskDuration9Estimated = 188744091,
    pjTaskDuration10Estimated = 188744092,
    pjTaskBaselineDurationEstimated = 188744093,
    pjTaskOutlineCode1 = 188744096,
    pjTaskOutlineCode2 = 188744098,
    pjTaskOutlineCode3 = 188744100,
    pjTaskOutlineCode4 = 188744102,
    pjTaskOutlineCode5 = 188744104,
    pjTaskOutlineCode6 = 188744106,
    pjTaskOutlineCode7 = 188744108,
    pjTaskOutlineCode8 = 188744110,
    pjTaskOutlineCode9 = 188744112,
    pjTaskOutlineCode10 = 188744114,
    pjTaskDeadline = 188744117,
    pjTaskStartSlack = 188744118,
    pjTaskFinishSlack = 188744119,
    pjTaskVAC = 188744121,
    pjTaskGroupBySummary = 188744126,
    pjTaskWBSPredecessors = 188744129,
    pjTaskWBSSuccessors = 188744130,
    pjTaskResourceType = 188744131,
    pjTaskHyperlinkScreenTip = 188744132,
    pjTaskBaseline1Start = 188744162,
    pjTaskBaseline1Finish = 188744163,
    pjTaskBaseline1Cost = 188744164,
    pjTaskBaseline1Work = 188744165,
    pjTaskBaseline1Duration = 188744167,
    pjTaskBaseline2Start = 188744173,
    pjTaskBaseline2Finish = 188744174,
    pjTaskBaseline2Cost = 188744175,
    pjTaskBaseline2Work = 188744176,
    pjTaskBaseline2Duration = 188744178,
    pjTaskBaseline3Start = 188744184,
    pjTaskBaseline3Finish = 188744185,
    pjTaskBaseline3Cost = 188744186,
    pjTaskBaseline3Work = 188744187,
    pjTaskBaseline3Duration = 188744189,
    pjTaskBaseline4Start = 188744195,
    pjTaskBaseline4Finish = 188744196,
    pjTaskBaseline4Cost = 188744197,
    pjTaskBaseline4Work = 188744198,
    pjTaskBaseline4Duration = 188744200,
    pjTaskBaseline5Start = 188744206,
    pjTaskBaseline5Finish = 188744207,
    pjTaskBaseline5Cost = 188744208,
    pjTaskBaseline5Work = 188744209,
    pjTaskBaseline5Duration = 188744211,
    pjTaskCPI = 188744217,
    pjTaskSPI = 188744218,
    pjTaskCVPercent = 188744219,
    pjTaskSVPercent = 188744220,
    pjTaskEAC = 188744221,
    pjTaskTCPI = 188744222,
    pjTaskStatus = 188744223,
    pjTaskBaseline6Start = 188744224,
    pjTaskBaseline6Finish = 188744225,
    pjTaskBaseline6Cost = 188744226,
    pjTaskBaseline6Work = 188744227,
    pjTaskBaseline6Duration = 188744229,
    pjTaskBaseline7Start = 188744235,
    pjTaskBaseline7Finish = 188744236,
    pjTaskBaseline7Cost = 188744237,
    pjTaskBaseline7Work = 188744238,
    pjTaskBaseline7Duration = 188744240,
    pjTaskBaseline8Start = 188744246,
    pjTaskBaseline8Finish = 188744247,
    pjTaskBaseline8Cost = 188744248,
    pjTaskBaseline8Work = 188744249,
    pjTaskBaseline8Duration = 188744251,
    pjTaskBaseline9Start = 188744257,
    pjTaskBaseline9Finish = 188744258,
    pjTaskBaseline9Cost = 188744259,
    pjTaskBaseline9Work = 188744260,
    pjTaskBaseline9Duration = 188744262,
    pjTaskBaseline10Start = 188744268,
    pjTaskBaseline10Finish = 188744269,
    pjTaskBaseline10Cost = 188744270,
    pjTaskBaseline10Work = 188744271,
    pjTaskBaseline10Duration = 188744273,
    pjTaskEnterpriseCost1 = 188744279,
    pjTaskEnterpriseCost2 = 188744280,
    pjTaskEnterpriseCost3 = 188744281,
    pjTaskEnterpriseCost4 = 188744282,
    pjTaskEnterpriseCost5 = 188744283,
    pjTaskEnterpriseCost6 = 188744284,
    pjTaskEnterpriseCost7 = 188744285,
    pjTaskEnterpriseCost8 = 188744286,
    pjTaskEnterpriseCost9 = 188744287,
    pjTaskEnterpriseCost10 = 188744288,
    pjTaskEnterpriseDate1 = 188744289,
    pjTaskEnterpriseDate2 = 188744290,
    pjTaskEnterpriseDate3 = 188744291,
    pjTaskEnterpriseDate4 = 188744292,
    pjTaskEnterpriseDate5 = 188744293,
    pjTaskEnterpriseDate6 = 188744294,
    pjTaskEnterpriseDate7 = 188744295,
    pjTaskEnterpriseDate8 = 188744296,
    pjTaskEnterpriseDate9 = 188744297,
    pjTaskEnterpriseDate10 = 188744298,
    pjTaskEnterpriseDate11 = 188744299,
    pjTaskEnterpriseDate12 = 188744300,
    pjTaskEnterpriseDate13 = 188744301,
    pjTaskEnterpriseDate14 = 188744302,
    pjTaskEnterpriseDate15 = 188744303,
    pjTaskEnterpriseDate16 = 188744304,
    pjTaskEnterpriseDate17 = 188744305,
    pjTaskEnterpriseDate18 = 188744306,
    pjTaskEnterpriseDate19 = 188744307,
    pjTaskEnterpriseDate20 = 188744308,
    pjTaskEnterpriseDate21 = 188744309,
    pjTaskEnterpriseDate22 = 188744310,
    pjTaskEnterpriseDate23 = 188744311,
    pjTaskEnterpriseDate24 = 188744312,
    pjTaskEnterpriseDate25 = 188744313,
    pjTaskEnterpriseDate26 = 188744314,
    pjTaskEnterpriseDate27 = 188744315,
    pjTaskEnterpriseDate28 = 188744316,
    pjTaskEnterpriseDate29 = 188744317,
    pjTaskEnterpriseDate30 = 188744318,
    pjTaskEnterpriseDuration1 = 188744319,
    pjTaskEnterpriseDuration2 = 188744320,
    pjTaskEnterpriseDuration3 = 188744321,
    pjTaskEnterpriseDuration4 = 188744322,
    pjTaskEnterpriseDuration5 = 188744323,
    pjTaskEnterpriseDuration6 = 188744324,
    pjTaskEnterpriseDuration7 = 188744325,
    pjTaskEnterpriseDuration8 = 188744326,
    pjTaskEnterpriseDuration9 = 188744327,
    pjTaskEnterpriseDuration10 = 188744328,
    pjTaskEnterpriseFlag1 = 188744339,
    pjTaskEnterpriseFlag2 = 188744340,
    pjTaskEnterpriseFlag3 = 188744341,
    pjTaskEnterpriseFlag4 = 188744342,
    pjTaskEnterpriseFlag5 = 188744343,
    pjTaskEnterpriseFlag6 = 188744344,
    pjTaskEnterpriseFlag7 = 188744345,
    pjTaskEnterpriseFlag8 = 188744346,
    pjTaskEnterpriseFlag9 = 188744347,
    pjTaskEnterpriseFlag10 = 188744348,
    pjTaskEnterpriseFlag11 = 188744349,
    pjTaskEnterpriseFlag12 = 188744350,
    pjTaskEnterpriseFlag13 = 188744351,
    pjTaskEnterpriseFlag14 = 188744352,
    pjTaskEnterpriseFlag15 = 188744353,
    pjTaskEnterpriseFlag16 = 188744354,
    pjTaskEnterpriseFlag17 = 188744355,
    pjTaskEnterpriseFlag18 = 188744356,
    pjTaskEnterpriseFlag19 = 188744357,
    pjTaskEnterpriseFlag20 = 188744358,
    pjTaskEnterpriseNumber1 = 188744379,
    pjTaskEnterpriseNumber2 = 188744380,
    pjTaskEnterpriseNumber3 = 188744381,
    pjTaskEnterpriseNumber4 = 188744382,
    pjTaskEnterpriseNumber5 = 188744383,
    pjTaskEnterpriseNumber6 = 188744384,
    pjTaskEnterpriseNumber7 = 188744385,
    pjTaskEnterpriseNumber8 = 188744386,
    pjTaskEnterpriseNumber9 = 188744387,
    pjTaskEnterpriseNumber10 = 188744388,
    pjTaskEnterpriseNumber11 = 188744389,
    pjTaskEnterpriseNumber12 = 188744390,
    pjTaskEnterpriseNumber13 = 188744391,
    pjTaskEnterpriseNumber14 = 188744392,
    pjTaskEnterpriseNumber15 = 188744393,
    pjTaskEnterpriseNumber16 = 188744394,
    pjTaskEnterpriseNumber17 = 188744395,
    pjTaskEnterpriseNumber18 = 188744396,
    pjTaskEnterpriseNumber19 = 188744397,
    pjTaskEnterpriseNumber20 = 188744398,
    pjTaskEnterpriseNumber21 = 188744399,
    pjTaskEnterpriseNumber22 = 188744400,
    pjTaskEnterpriseNumber23 = 188744401,
    pjTaskEnterpriseNumber24 = 188744402,
    pjTaskEnterpriseNumber25 = 188744403,
    pjTaskEnterpriseNumber26 = 188744404,
    pjTaskEnterpriseNumber27 = 188744405,
    pjTaskEnterpriseNumber28 = 188744406,
    pjTaskEnterpriseNumber29 = 188744407,
    pjTaskEnterpriseNumber30 = 188744408,
    pjTaskEnterpriseNumber31 = 188744409,
    pjTaskEnterpriseNumber32 = 188744410,
    pjTaskEnterpriseNumber33 = 188744411,
    pjTaskEnterpriseNumber34 = 188744412,
    pjTaskEnterpriseNumber35 = 188744413,
    pjTaskEnterpriseNumber36 = 188744414,
    pjTaskEnterpriseNumber37 = 188744415,
    pjTaskEnterpriseNumber38 = 188744416,
    pjTaskEnterpriseNumber39 = 188744417,
    pjTaskEnterpriseNumber40 = 188744418,
    pjTaskEnterpriseOutlineCode1 = 188744419,
    pjTaskEnterpriseOutlineCode2 = 188744421,
    pjTaskEnterpriseOutlineCode3 = 188744423,
    pjTaskEnterpriseOutlineCode4 = 188744425,
    pjTaskEnterpriseOutlineCode5 = 188744427,
    pjTaskEnterpriseOutlineCode6 = 188744429,
    pjTaskEnterpriseOutlineCode7 = 188744431,
    pjTaskEnterpriseOutlineCode8 = 188744433,
    pjTaskEnterpriseOutlineCode9 = 188744435,
    pjTaskEnterpriseOutlineCode10 = 188744437,
    pjTaskEnterpriseOutlineCode11 = 188744439,
    pjTaskEnterpriseOutlineCode12 = 188744441,
    pjTaskEnterpriseOutlineCode13 = 188744443,
    pjTaskEnterpriseOutlineCode14 = 188744445,
    pjTaskEnterpriseOutlineCode15 = 188744447,
    pjTaskEnterpriseOutlineCode16 = 188744449,
    pjTaskEnterpriseOutlineCode17 = 188744451,
    pjTaskEnterpriseOutlineCode18 = 188744453,
    pjTaskEnterpriseOutlineCode19 = 188744455,
    pjTaskEnterpriseOutlineCode20 = 188744457,
    pjTaskEnterpriseOutlineCode21 = 188744459,
    pjTaskEnterpriseOutlineCode22 = 188744461,
    pjTaskEnterpriseOutlineCode23 = 188744463,
    pjTaskEnterpriseOutlineCode24 = 188744465,
    pjTaskEnterpriseOutlineCode25 = 188744467,
    pjTaskEnterpriseOutlineCode26 = 188744469,
    pjTaskEnterpriseOutlineCode27 = 188744471,
    pjTaskEnterpriseOutlineCode28 = 188744473,
    pjTaskEnterpriseOutlineCode29 = 188744475,
    pjTaskEnterpriseOutlineCode30 = 188744477,
    pjTaskEnterpriseText1 = 188744479,
    pjTaskEnterpriseText2 = 188744480,
    pjTaskEnterpriseText3 = 188744481,
    pjTaskEnterpriseText4 = 188744482,
    pjTaskEnterpriseText5 = 188744483,
    pjTaskEnterpriseText6 = 188744484,
    pjTaskEnterpriseText7 = 188744485,
    pjTaskEnterpriseText8 = 188744486,
    pjTaskEnterpriseText9 = 188744487,
    pjTaskEnterpriseText10 = 188744488,
    pjTaskEnterpriseText11 = 188744489,
    pjTaskEnterpriseText12 = 188744490,
    pjTaskEnterpriseText13 = 188744491,
    pjTaskEnterpriseText14 = 188744492,
    pjTaskEnterpriseText15 = 188744493,
    pjTaskEnterpriseText16 = 188744494,
    pjTaskEnterpriseText17 = 188744495,
    pjTaskEnterpriseText18 = 188744496,
    pjTaskEnterpriseText19 = 188744497,
    pjTaskEnterpriseText20 = 188744498,
    pjTaskEnterpriseText21 = 188744499,
    pjTaskEnterpriseText22 = 188744500,
    pjTaskEnterpriseText23 = 188744501,
    pjTaskEnterpriseText24 = 188744502,
    pjTaskEnterpriseText25 = 188744503,
    pjTaskEnterpriseText26 = 188744504,
    pjTaskEnterpriseText27 = 188744505,
    pjTaskEnterpriseText28 = 188744506,
    pjTaskEnterpriseText29 = 188744507,
    pjTaskEnterpriseText30 = 188744508,
    pjTaskEnterpriseText31 = 188744509,
    pjTaskEnterpriseText32 = 188744510,
    pjTaskEnterpriseText33 = 188744511,
    pjTaskEnterpriseText34 = 188744512,
    pjTaskEnterpriseText35 = 188744513,
    pjTaskEnterpriseText36 = 188744514,
    pjTaskEnterpriseText37 = 188744515,
    pjTaskEnterpriseText38 = 188744516,
    pjTaskEnterpriseText39 = 188744517,
    pjTaskEnterpriseText40 = 188744518,
    pjTaskBaseline1DurationEstimated = 188744519,
    pjTaskBaseline2DurationEstimated = 188744520,
    pjTaskBaseline3DurationEstimated = 188744521,
    pjTaskBaseline4DurationEstimated = 188744522,
    pjTaskBaseline5DurationEstimated = 188744523,
    pjTaskBaseline6DurationEstimated = 188744524,
    pjTaskBaseline7DurationEstimated = 188744525,
    pjTaskBaseline8DurationEstimated = 188744526,
    pjTaskBaseline9DurationEstimated = 188744527,
    pjTaskBaseline10DurationEstimated = 188744528,
    pjTaskEnterpriseProjectCost1 = 188744529,
    pjTaskEnterpriseProjectCost2 = 188744530,
    pjTaskEnterpriseProjectCost3 = 188744531,
    pjTaskEnterpriseProjectCost4 = 188744532,
    pjTaskEnterpriseProjectCost5 = 188744533,
    pjTaskEnterpriseProjectCost6 = 188744534,
    pjTaskEnterpriseProjectCost7 = 188744535,
    pjTaskEnterpriseProjectCost8 = 188744536,
    pjTaskEnterpriseProjectCost9 = 188744537,
    pjTaskEnterpriseProjectCost10 = 188744538,
    pjTaskEnterpriseProjectDate1 = 188744539,
    pjTaskEnterpriseProjectDate2 = 188744540,
    pjTaskEnterpriseProjectDate3 = 188744541,
    pjTaskEnterpriseProjectDate4 = 188744542,
    pjTaskEnterpriseProjectDate5 = 188744543,
    pjTaskEnterpriseProjectDate6 = 188744544,
    pjTaskEnterpriseProjectDate7 = 188744545,
    pjTaskEnterpriseProjectDate8 = 188744546,
    pjTaskEnterpriseProjectDate9 = 188744547,
    pjTaskEnterpriseProjectDate10 = 188744548,
    pjTaskEnterpriseProjectDate11 = 188744549,
    pjTaskEnterpriseProjectDate12 = 188744550,
    pjTaskEnterpriseProjectDate13 = 188744551,
    pjTaskEnterpriseProjectDate14 = 188744552,
    pjTaskEnterpriseProjectDate15 = 188744553,
    pjTaskEnterpriseProjectDate16 = 188744554,
    pjTaskEnterpriseProjectDate17 = 188744555,
    pjTaskEnterpriseProjectDate18 = 188744556,
    pjTaskEnterpriseProjectDate19 = 188744557,
    pjTaskEnterpriseProjectDate20 = 188744558,
    pjTaskEnterpriseProjectDate21 = 188744559,
    pjTaskEnterpriseProjectDate22 = 188744560,
    pjTaskEnterpriseProjectDate23 = 188744561,
    pjTaskEnterpriseProjectDate24 = 188744562,
    pjTaskEnterpriseProjectDate25 = 188744563,
    pjTaskEnterpriseProjectDate26 = 188744564,
    pjTaskEnterpriseProjectDate27 = 188744565,
    pjTaskEnterpriseProjectDate28 = 188744566,
    pjTaskEnterpriseProjectDate29 = 188744567,
    pjTaskEnterpriseProjectDate30 = 188744568,
    pjTaskEnterpriseProjectDuration1 = 188744569,
    pjTaskEnterpriseProjectDuration2 = 188744570,
    pjTaskEnterpriseProjectDuration3 = 188744571,
    pjTaskEnterpriseProjectDuration4 = 188744572,
    pjTaskEnterpriseProjectDuration5 = 188744573,
    pjTaskEnterpriseProjectDuration6 = 188744574,
    pjTaskEnterpriseProjectDuration7 = 188744575,
    pjTaskEnterpriseProjectDuration8 = 188744576,
    pjTaskEnterpriseProjectDuration9 = 188744577,
    pjTaskEnterpriseProjectDuration10 = 188744578,
    pjTaskEnterpriseProjectOutlineCode1 = 188744589,
    pjTaskEnterpriseProjectOutlineCode2 = 188744590,
    pjTaskEnterpriseProjectOutlineCode3 = 188744591,
    pjTaskEnterpriseProjectOutlineCode4 = 188744592,
    pjTaskEnterpriseProjectOutlineCode5 = 188744593,
    pjTaskEnterpriseProjectOutlineCode6 = 188744594,
    pjTaskEnterpriseProjectOutlineCode7 = 188744595,
    pjTaskEnterpriseProjectOutlineCode8 = 188744596,
    pjTaskEnterpriseProjectOutlineCode9 = 188744597,
    pjTaskEnterpriseProjectOutlineCode10 = 188744598,
    pjTaskEnterpriseProjectOutlineCode11 = 188744599,
    pjTaskEnterpriseProjectOutlineCode12 = 188744600,
    pjTaskEnterpriseProjectOutlineCode13 = 188744601,
    pjTaskEnterpriseProjectOutlineCode14 = 188744602,
    pjTaskEnterpriseProjectOutlineCode15 = 188744603,
    pjTaskEnterpriseProjectOutlineCode16 = 188744604,
    pjTaskEnterpriseProjectOutlineCode17 = 188744605,
    pjTaskEnterpriseProjectOutlineCode18 = 188744606,
    pjTaskEnterpriseProjectOutlineCode19 = 188744607,
    pjTaskEnterpriseProjectOutlineCode20 = 188744608,
    pjTaskEnterpriseProjectOutlineCode21 = 188744609,
    pjTaskEnterpriseProjectOutlineCode22 = 188744610,
    pjTaskEnterpriseProjectOutlineCode23 = 188744611,
    pjTaskEnterpriseProjectOutlineCode24 = 188744612,
    pjTaskEnterpriseProjectOutlineCode25 = 188744613,
    pjTaskEnterpriseProjectOutlineCode26 = 188744614,
    pjTaskEnterpriseProjectOutlineCode27 = 188744615,
    pjTaskEnterpriseProjectOutlineCode28 = 188744616,
    pjTaskEnterpriseProjectOutlineCode29 = 188744617,
    pjTaskEnterpriseProjectOutlineCode30 = 188744618,
    pjTaskEnterpriseProjectFlag1 = 188744649,
    pjTaskEnterpriseProjectFlag2 = 188744650,
    pjTaskEnterpriseProjectFlag3 = 188744651,
    pjTaskEnterpriseProjectFlag4 = 188744652,
    pjTaskEnterpriseProjectFlag5 = 188744653,
    pjTaskEnterpriseProjectFlag6 = 188744654,
    pjTaskEnterpriseProjectFlag7 = 188744655,
    pjTaskEnterpriseProjectFlag8 = 188744656,
    pjTaskEnterpriseProjectFlag9 = 188744657,
    pjTaskEnterpriseProjectFlag10 = 188744658,
    pjTaskEnterpriseProjectFlag11 = 188744659,
    pjTaskEnterpriseProjectFlag12 = 188744660,
    pjTaskEnterpriseProjectFlag13 = 188744661,
    pjTaskEnterpriseProjectFlag14 = 188744662,
    pjTaskEnterpriseProjectFlag15 = 188744663,
    pjTaskEnterpriseProjectFlag16 = 188744664,
    pjTaskEnterpriseProjectFlag17 = 188744665,
    pjTaskEnterpriseProjectFlag18 = 188744666,
    pjTaskEnterpriseProjectFlag19 = 188744667,
    pjTaskEnterpriseProjectFlag20 = 188744668,
    pjTaskEnterpriseProjectNumber1 = 188744689,
    pjTaskEnterpriseProjectNumber2 = 188744690,
    pjTaskEnterpriseProjectNumber3 = 188744691,
    pjTaskEnterpriseProjectNumber4 = 188744692,
    pjTaskEnterpriseProjectNumber5 = 188744693,
    pjTaskEnterpriseProjectNumber6 = 188744694,
    pjTaskEnterpriseProjectNumber7 = 188744695,
    pjTaskEnterpriseProjectNumber8 = 188744696,
    pjTaskEnterpriseProjectNumber9 = 188744697,
    pjTaskEnterpriseProjectNumber10 = 188744698,
    pjTaskEnterpriseProjectNumber11 = 188744699,
    pjTaskEnterpriseProjectNumber12 = 188744700,
    pjTaskEnterpriseProjectNumber13 = 188744701,
    pjTaskEnterpriseProjectNumber14 = 188744702,
    pjTaskEnterpriseProjectNumber15 = 188744703,
    pjTaskEnterpriseProjectNumber16 = 188744704,
    pjTaskEnterpriseProjectNumber17 = 188744705,
    pjTaskEnterpriseProjectNumber18 = 188744706,
    pjTaskEnterpriseProjectNumber19 = 188744707,
    pjTaskEnterpriseProjectNumber20 = 188744708,
    pjTaskEnterpriseProjectNumber21 = 188744709,
    pjTaskEnterpriseProjectNumber22 = 188744710,
    pjTaskEnterpriseProjectNumber23 = 188744711,
    pjTaskEnterpriseProjectNumber24 = 188744712,
    pjTaskEnterpriseProjectNumber25 = 188744713,
    pjTaskEnterpriseProjectNumber26 = 188744714,
    pjTaskEnterpriseProjectNumber27 = 188744715,
    pjTaskEnterpriseProjectNumber28 = 188744716,
    pjTaskEnterpriseProjectNumber29 = 188744717,
    pjTaskEnterpriseProjectNumber30 = 188744718,
    pjTaskEnterpriseProjectNumber31 = 188744719,
    pjTaskEnterpriseProjectNumber32 = 188744720,
    pjTaskEnterpriseProjectNumber33 = 188744721,
    pjTaskEnterpriseProjectNumber34 = 188744722,
    pjTaskEnterpriseProjectNumber35 = 188744723,
    pjTaskEnterpriseProjectNumber36 = 188744724,
    pjTaskEnterpriseProjectNumber37 = 188744725,
    pjTaskEnterpriseProjectNumber38 = 188744726,
    pjTaskEnterpriseProjectNumber39 = 188744727,
    pjTaskEnterpriseProjectNumber40 = 188744728,
    pjTaskEnterpriseProjectText1 = 188744729,
    pjTaskEnterpriseProjectText2 = 188744730,
    pjTaskEnterpriseProjectText3 = 188744731,
    pjTaskEnterpriseProjectText4 = 188744732,
    pjTaskEnterpriseProjectText5 = 188744733,
    pjTaskEnterpriseProjectText6 = 188744734,
    pjTaskEnterpriseProjectText7 = 188744735,
    pjTaskEnterpriseProjectText8 = 188744736,
    pjTaskEnterpriseProjectText9 = 188744737,
    pjTaskEnterpriseProjectText10 = 188744738,
    pjTaskEnterpriseProjectText11 = 188744739,
    pjTaskEnterpriseProjectText12 = 188744740,
    pjTaskEnterpriseProjectText13 = 188744741,
    pjTaskEnterpriseProjectText14 = 188744742,
    pjTaskEnterpriseProjectText15 = 188744743,
    pjTaskEnterpriseProjectText16 = 188744744,
    pjTaskEnterpriseProjectText17 = 188744745,
    pjTaskEnterpriseProjectText18 = 188744746,
    pjTaskEnterpriseProjectText19 = 188744747,
    pjTaskEnterpriseProjectText20 = 188744748,
    pjTaskEnterpriseProjectText21 = 188744749,
    pjTaskEnterpriseProjectText22 = 188744750,
    pjTaskEnterpriseProjectText23 = 188744751,
    pjTaskEnterpriseProjectText24 = 188744752,
    pjTaskEnterpriseProjectText25 = 188744753,
    pjTaskEnterpriseProjectText26 = 188744754,
    pjTaskEnterpriseProjectText27 = 188744755,
    pjTaskEnterpriseProjectText28 = 188744756,
    pjTaskEnterpriseProjectText29 = 188744757,
    pjTaskEnterpriseProjectText30 = 188744758,
    pjTaskEnterpriseProjectText31 = 188744759,
    pjTaskEnterpriseProjectText32 = 188744760,
    pjTaskEnterpriseProjectText33 = 188744761,
    pjTaskEnterpriseProjectText34 = 188744762,
    pjTaskEnterpriseProjectText35 = 188744763,
    pjTaskEnterpriseProjectText36 = 188744764,
    pjTaskEnterpriseProjectText37 = 188744765,
    pjTaskEnterpriseProjectText38 = 188744766,
    pjTaskEnterpriseProjectText39 = 188744767,
    pjTaskEnterpriseProjectText40 = 188744768,
    pjTaskResourceEnterpriseOutlineCode1 = 188744769,
    pjTaskResourceEnterpriseOutlineCode2 = 188744770,
    pjTaskResourceEnterpriseOutlineCode3 = 188744771,
    pjTaskResourceEnterpriseOutlineCode4 = 188744772,
    pjTaskResourceEnterpriseOutlineCode5 = 188744773,
    pjTaskResourceEnterpriseOutlineCode6 = 188744774,
    pjTaskResourceEnterpriseOutlineCode7 = 188744775,
    pjTaskResourceEnterpriseOutlineCode8 = 188744776,
    pjTaskResourceEnterpriseOutlineCode9 = 188744777,
    pjTaskResourceEnterpriseOutlineCode10 = 188744778,
    pjTaskResourceEnterpriseOutlineCode11 = 188744779,
    pjTaskResourceEnterpriseOutlineCode12 = 188744780,
    pjTaskResourceEnterpriseOutlineCode13 = 188744781,
    pjTaskResourceEnterpriseOutlineCode14 = 188744782,
    pjTaskResourceEnterpriseOutlineCode15 = 188744783,
    pjTaskResourceEnterpriseOutlineCode16 = 188744784,
    pjTaskResourceEnterpriseOutlineCode17 = 188744785,
    pjTaskResourceEnterpriseOutlineCode18 = 188744786,
    pjTaskResourceEnterpriseOutlineCode19 = 188744787,
    pjTaskResourceEnterpriseOutlineCode20 = 188744788,
    pjTaskResourceEnterpriseOutlineCode21 = 188744789,
    pjTaskResourceEnterpriseOutlineCode22 = 188744790,
    pjTaskResourceEnterpriseOutlineCode23 = 188744791,
    pjTaskResourceEnterpriseOutlineCode24 = 188744792,
    pjTaskResourceEnterpriseOutlineCode25 = 188744793,
    pjTaskResourceEnterpriseOutlineCode26 = 188744794,
    pjTaskResourceEnterpriseOutlineCode27 = 188744795,
    pjTaskResourceEnterpriseOutlineCode28 = 188744796,
    pjTaskResourceEnterpriseOutlineCode29 = 188744797,
    pjTaskResourceEnterpriseRBS = 188744798,
    pjTaskPhysicalPercentComplete = 188744799,
    pjTaskDemandedRequested = 188744800,
    pjTaskStatusIndicator = 188744801,
    pjTaskEarnedValueMethod = 188744802,
    pjTaskResourceEnterpriseMultiValueCode20 = 188744809,
    pjTaskResourceEnterpriseMultiValueCode21 = 188744810,
    pjTaskResourceEnterpriseMultiValueCode22 = 188744811,
    pjTaskResourceEnterpriseMultiValueCode23 = 188744812,
    pjTaskResourceEnterpriseMultiValueCode24 = 188744813,
    pjTaskResourceEnterpriseMultiValueCode25 = 188744814,
    pjTaskResourceEnterpriseMultiValueCode26 = 188744815,
    pjTaskResourceEnterpriseMultiValueCode27 = 188744816,
    pjTaskResourceEnterpriseMultiValueCode28 = 188744817,
    pjTaskResourceEnterpriseMultiValueCode29 = 188744818,
    pjTaskActualWorkProtected = 188744819,
    pjTaskActualOvertimeWorkProtected = 188744820,
    pjTaskGuid = 188744823,
    pjTaskCalendarGuid = 188744824,
    pjTaskDeliverableGuid = 188744826,
    pjTaskDeliverableType = 188744827,
    pjTaskDeliverableStart = 188744832,
    pjTaskDeliverableFinish = 188744833,
    pjTaskIsPublished = 188744845,
    pjTaskStatusManagerName = 188744846,
    pjTaskErrorMessage = 188744847,
    pjTaskBudgetWork = 188744851,
    pjTaskBudgetCost = 188744852,
    pjTaskBaselineFixedCostAccrual = 188744853,
    pjTaskBaselineDeliverableStart = 188744854,
    pjTaskBaselineDeliverableFinish = 188744855,
    pjTaskBaselineBudgetWork = 188744856,
    pjTaskBaselineBudgetCost = 188744857,
    pjTaskBaseline1FixedCostAccrual = 188744860,
    pjTaskBaseline1DeliverableStart = 188744861,
    pjTaskBaseline1DeliverableFinish = 188744862,
    pjTaskBaseline1BudgetWork = 188744863,
    pjTaskBaseline1BudgetCost = 188744864,
    pjTaskBaseline2FixedCostAccrual = 188744867,
    pjTaskBaseline2DeliverableStart = 188744868,
    pjTaskBaseline2DeliverableFinish = 188744869,
    pjTaskBaseline2BudgetWork = 188744870,
    pjTaskBaseline2BudgetCost = 188744871,
    pjTaskBaseline3FixedCostAccrual = 188744874,
    pjTaskBaseline3DeliverableStart = 188744875,
    pjTaskBaseline3DeliverableFinish = 188744876,
    pjTaskBaseline3BudgetWork = 188744877,
    pjTaskBaseline3BudgetCost = 188744878,
    pjTaskBaseline4FixedCostAccrual = 188744881,
    pjTaskBaseline4DeliverableStart = 188744882,
    pjTaskBaseline4DeliverableFinish = 188744883,
    pjTaskBaseline4BudgetWork = 188744884,
    pjTaskBaseline4BudgetCost = 188744885,
    pjTaskBaseline5FixedCostAccrual = 188744888,
    pjTaskBaseline5DeliverableStart = 188744889,
    pjTaskBaseline5DeliverableFinish = 188744890,
    pjTaskBaseline5BudgetWork = 188744891,
    pjTaskBaseline5BudgetCost = 188744892,
    pjTaskBaseline6FixedCostAccrual = 188744895,
    pjTaskBaseline6DeliverableStart = 188744896,
    pjTaskBaseline6DeliverableFinish = 188744897,
    pjTaskBaseline6BudgetWork = 188744898,
    pjTaskBaseline6BudgetCost = 188744899,
    pjTaskBaseline7FixedCostAccrual = 188744902,
    pjTaskBaseline7DeliverableStart = 188744903,
    pjTaskBaseline7DeliverableFinish = 188744904,
    pjTaskBaseline7BudgetWork = 188744905,
    pjTaskBaseline7BudgetCost = 188744906,
    pjTaskBaseline8FixedCostAccrual = 188744909,
    pjTaskBaseline8DeliverableStart = 188744910,
    pjTaskBaseline8DeliverableFinish = 188744911,
    pjTaskBaseline8BudgetWork = 188744912,
    pjTaskBaseline8BudgetCost = 188744913,
    pjTaskBaseline9FixedCostAccrual = 188744916,
    pjTaskBaseline9DeliverableStart = 188744917,
    pjTaskBaseline9DeliverableFinish = 188744918,
    pjTaskBaseline9BudgetWork = 188744919,
    pjTaskBaseline9BudgetCost = 188744920,
    pjTaskBaseline10FixedCostAccrual = 188744923,
    pjTaskBaseline10DeliverableStart = 188744924,
    pjTaskBaseline10DeliverableFinish = 188744925,
    pjTaskBaseline10BudgetWork = 188744926,
    pjTaskBaseline10BudgetCost = 188744927,
    pjTaskRecalcFlags = 188744930,
    pjTaskDeliverableName = 188744956,
    pjTaskActive = 188744959,
    pjTaskManual = 188744960,
    pjTaskPlaceholder = 188744961,
    pjTaskWarning = 188744962,
    pjTaskStartText = 188744965,
    pjTaskFinishText = 188744966,
    pjTaskDurationText = 188744967,
    pjTaskIsStartValid = 188744975,
    pjTaskIsFinishValid = 188744976,
    pjTaskIsDurationValid = 188744977,
    pjTaskBaselineStartText = 188744979,
    pjTaskBaselineFinishText = 188744980,
    pjTaskBaselineDurationText = 188744981,
    pjTaskBaseline1StartText = 188744982,
    pjTaskBaseline1FinishText = 188744983,
    pjTaskBaseline1DurationText = 188744984,
    pjTaskBaseline2StartText = 188744985,
    pjTaskBaseline2FinishText = 188744986,
    pjTaskBaseline2DurationText = 188744987,
    pjTaskBaseline3StartText = 188744988,
    pjTaskBaseline3FinishText = 188744989,
    pjTaskBaseline3DurationText = 188744990,
    pjTaskBaseline4StartText = 188744991,
    pjTaskBaseline4FinishText = 188744992,
    pjTaskBaseline4DurationText = 188744993,
    pjTaskBaseline5StartText = 188744994,
    pjTaskBaseline5FinishText = 188744995,
    pjTaskBaseline5DurationText = 188744996,
    pjTaskBaseline6StartText = 188744997,
    pjTaskBaseline6FinishText = 188744998,
    pjTaskBaseline6DurationText = 188744999,
    pjTaskBaseline7StartText = 188745000,
    pjTaskBaseline7FinishText = 188745001,
    pjTaskBaseline7DurationText = 188745002,
    pjTaskBaseline8StartText = 188745003,
    pjTaskBaseline8FinishText = 188745004,
    pjTaskBaseline8DurationText = 188745005,
    pjTaskBaseline9StartText = 188745006,
    pjTaskBaseline9FinishText = 188745007,
    pjTaskBaseline9DurationText = 188745008,
    pjTaskBaseline10StartText = 188745009,
    pjTaskBaseline10FinishText = 188745010,
    pjTaskBaseline10DurationText = 188745011,
    pjTaskIgnoreWarnings = 188745012,
    pjTaskAssignmentPeakUnits = 188745015,
    pjTaskScheduledStart = 188745018,
    pjTaskScheduledFinish = 188745019,
    pjTaskScheduledDuration = 188745020,
    pjTaskPathDrivingPredecessor = 188745061,
    pjTaskPathPredecessor = 188745062,
    pjTaskPathDrivenSuccessor = 188745063,
    pjTaskPathSuccessor = 188745064,
    pjResourceID = 205520896,
    pjResourceName = 205520897,
    pjResourceInitials = 205520898,
    pjResourceGroup = 205520899,
    pjResourceMaxUnits = 205520900,
    pjResourceBaseCalendar = 205520901,
    pjResourceStandardRate = 205520902,
    pjResourceOvertimeRate = 205520903,
    pjResourceText1 = 205520904,
    pjResourceText2 = 205520905,
    pjResourceCode = 205520906,
    pjResourceActualCost = 205520907,
    pjResourceCost = 205520908,
    pjResourceWork = 205520909,
    pjResourceActualWork = 205520910,
    pjResourceBaselineWork = 205520911,
    pjResourceOvertimeWork = 205520912,
    pjResourceBaselineCost = 205520913,
    pjResourceCostPerUse = 205520914,
    pjResourceAccrueAt = 205520915,
    pjResourceNotes = 205520916,
    pjResourceRemainingCost = 205520917,
    pjResourceRemainingWork = 205520918,
    pjResourceWorkVariance = 205520919,
    pjResourceCostVariance = 205520920,
    pjResourceOverallocated = 205520921,
    pjResourcePeakUnits = 205520922,
    pjResourceUniqueID = 205520923,
    pjResourceSheetNotes = 205520924,
    pjResourcePercentWorkComplete = 205520925,
    pjResourceText3 = 205520926,
    pjResourceText4 = 205520927,
    pjResourceText5 = 205520928,
    pjResourceObjects = 205520929,
    pjResourceLinkedFields = 205520930,
    pjResourceEMailAddress = 205520931,
    pjResourceRegularWork = 205520934,
    pjResourceActualOvertimeWork = 205520935,
    pjResourceRemainingOvertimeWork = 205520936,
    pjResourceOvertimeCost = 205520943,
    pjResourceActualOvertimeCost = 205520944,
    pjResourceRemainingOvertimeCost = 205520945,
    pjResourceBCWS = 205520947,
    pjResourceBCWP = 205520948,
    pjResourceACWP = 205520949,
    pjResourceSV = 205520950,
    pjResourceAvailableFrom = 205520953,
    pjResourceAvailableTo = 205520954,
    pjResourceIndicators = 205520982,
    pjResourceText6 = 205520993,
    pjResourceText7 = 205520994,
    pjResourceText8 = 205520995,
    pjResourceText9 = 205520996,
    pjResourceText10 = 205520997,
    pjResourceStart1 = 205520998,
    pjResourceStart2 = 205520999,
    pjResourceStart3 = 205521000,
    pjResourceStart4 = 205521001,
    pjResourceStart5 = 205521002,
    pjResourceFinish1 = 205521003,
    pjResourceFinish2 = 205521004,
    pjResourceFinish3 = 205521005,
    pjResourceFinish4 = 205521006,
    pjResourceFinish5 = 205521007,
    pjResourceNumber1 = 205521008,
    pjResourceNumber2 = 205521009,
    pjResourceNumber3 = 205521010,
    pjResourceNumber4 = 205521011,
    pjResourceNumber5 = 205521012,
    pjResourceDuration1 = 205521013,
    pjResourceDuration2 = 205521014,
    pjResourceDuration3 = 205521015,
    pjResourceCost1 = 205521019,
    pjResourceCost2 = 205521020,
    pjResourceCost3 = 205521021,
    pjResourceFlag10 = 205521022,
    pjResourceFlag1 = 205521023,
    pjResourceFlag2 = 205521024,
    pjResourceFlag3 = 205521025,
    pjResourceFlag4 = 205521026,
    pjResourceFlag5 = 205521027,
    pjResourceFlag6 = 205521028,
    pjResourceFlag7 = 205521029,
    pjResourceFlag8 = 205521030,
    pjResourceFlag9 = 205521031,
    pjResourceHyperlink = 205521034,
    pjResourceHyperlinkAddress = 205521035,
    pjResourceHyperlinkSubAddress = 205521036,
    pjResourceHyperlinkHref = 205521037,
    pjResourceIsAssignment = 205521040,
    pjResourceTaskSummaryName = 205521055,
    pjResourceCanLevel = 205521059,
    pjResourceWorkContour = 205521060,
    pjResourceCost4 = 205521062,
    pjResourceCost5 = 205521063,
    pjResourceCost6 = 205521064,
    pjResourceCost7 = 205521065,
    pjResourceCost8 = 205521066,
    pjResourceCost9 = 205521067,
    pjResourceCost10 = 205521068,
    pjResourceDate1 = 205521069,
    pjResourceDate2 = 205521070,
    pjResourceDate3 = 205521071,
    pjResourceDate4 = 205521072,
    pjResourceDate5 = 205521073,
    pjResourceDate6 = 205521074,
    pjResourceDate7 = 205521075,
    pjResourceDate8 = 205521076,
    pjResourceDate9 = 205521077,
    pjResourceDate10 = 205521078,
    pjResourceDuration4 = 205521079,
    pjResourceDuration5 = 205521080,
    pjResourceDuration6 = 205521081,
    pjResourceDuration7 = 205521082,
    pjResourceDuration8 = 205521083,
    pjResourceDuration9 = 205521084,
    pjResourceDuration10 = 205521085,
    pjResourceFinish6 = 205521086,
    pjResourceFinish7 = 205521087,
    pjResourceFinish8 = 205521088,
    pjResourceFinish9 = 205521089,
    pjResourceFinish10 = 205521090,
    pjResourceFlag11 = 205521091,
    pjResourceFlag12 = 205521092,
    pjResourceFlag13 = 205521093,
    pjResourceFlag14 = 205521094,
    pjResourceFlag15 = 205521095,
    pjResourceFlag16 = 205521096,
    pjResourceFlag17 = 205521097,
    pjResourceFlag18 = 205521098,
    pjResourceFlag19 = 205521099,
    pjResourceFlag20 = 205521100,
    pjResourceNumber6 = 205521101,
    pjResourceNumber7 = 205521102,
    pjResourceNumber8 = 205521103,
    pjResourceNumber9 = 205521104,
    pjResourceNumber10 = 205521105,
    pjResourceNumber11 = 205521106,
    pjResourceNumber12 = 205521107,
    pjResourceNumber13 = 205521108,
    pjResourceNumber14 = 205521109,
    pjResourceNumber15 = 205521110,
    pjResourceNumber16 = 205521111,
    pjResourceNumber17 = 205521112,
    pjResourceNumber18 = 205521113,
    pjResourceNumber19 = 205521114,
    pjResourceNumber20 = 205521115,
    pjResourceStart6 = 205521116,
    pjResourceStart7 = 205521117,
    pjResourceStart8 = 205521118,
    pjResourceStart9 = 205521119,
    pjResourceStart10 = 205521120,
    pjResourceText11 = 205521121,
    pjResourceText12 = 205521122,
    pjResourceText13 = 205521123,
    pjResourceText14 = 205521124,
    pjResourceText15 = 205521125,
    pjResourceText16 = 205521126,
    pjResourceText17 = 205521127,
    pjResourceText18 = 205521128,
    pjResourceText19 = 205521129,
    pjResourceText20 = 205521130,
    pjResourceText21 = 205521131,
    pjResourceText22 = 205521132,
    pjResourceText23 = 205521133,
    pjResourceText24 = 205521134,
    pjResourceText25 = 205521135,
    pjResourceText26 = 205521136,
    pjResourceText27 = 205521137,
    pjResourceText28 = 205521138,
    pjResourceText29 = 205521139,
    pjResourceText30 = 205521140,
    pjResourcePhonetics = 205521148,
    pjResourceIndex = 205521149,
    pjResourceAssignmentDelay = 205521153,
    pjResourceAssignmentUnits = 205521154,
    pjResourceBaselineStart = 205521155,
    pjResourceBaselineFinish = 205521156,
    pjResourceConfirmed = 205521157,
    pjResourceFinish = 205521158,
    pjResourceLevelingDelay = 205521159,
    pjResourceResponsePending = 205521160,
    pjResourceStart = 205521161,
    pjResourceTeamStatusPending = 205521162,
    pjResourceUpdateNeeded = 205521163,
    pjResourceCV = 205521164,
    pjResourceCostRateTable = 205521165,
    pjResourceWorkgroup = 205521168,
    pjResourceProject = 205521169,
    pjResourceOutlineCode1 = 205521174,
    pjResourceOutlineCode2 = 205521176,
    pjResourceOutlineCode3 = 205521178,
    pjResourceOutlineCode4 = 205521180,
    pjResourceOutlineCode5 = 205521182,
    pjResourceOutlineCode6 = 205521184,
    pjResourceOutlineCode7 = 205521186,
    pjResourceOutlineCode8 = 205521188,
    pjResourceOutlineCode9 = 205521190,
    pjResourceOutlineCode10 = 205521192,
    pjResourceMaterialLabel = 205521195,
    pjResourceType = 205521196,
    pjResourceVAC = 205521197,
    pjResourceGroupbySummary = 205521202,
    pjResourceWindowsUserAccount = 205521207,
    pjResourceHyperlinkScreenTip = 205521208,
    pjResourceWBS = 205521236,
    pjResourceBaseline1Work = 205521238,
    pjResourceBaseline1Cost = 205521239,
    pjResourceBaseline1Start = 205521244,
    pjResourceBaseline1Finish = 205521245,
    pjResourceBaseline2Work = 205521248,
    pjResourceBaseline2Cost = 205521249,
    pjResourceBaseline2Start = 205521254,
    pjResourceBaseline2Finish = 205521255,
    pjResourceBaseline3Work = 205521258,
    pjResourceBaseline3Cost = 205521259,
    pjResourceBaseline3Start = 205521264,
    pjResourceBaseline3Finish = 205521265,
    pjResourceBaseline4Work = 205521268,
    pjResourceBaseline4Cost = 205521269,
    pjResourceBaseline4Start = 205521274,
    pjResourceBaseline4Finish = 205521275,
    pjResourceBaseline5Work = 205521278,
    pjResourceBaseline5Cost = 205521279,
    pjResourceBaseline5Start = 205521284,
    pjResourceBaseline5Finish = 205521285,
    pjResourceBaseline6Work = 205521288,
    pjResourceBaseline6Cost = 205521289,
    pjResourceBaseline6Start = 205521294,
    pjResourceBaseline6Finish = 205521295,
    pjResourceBaseline7Work = 205521298,
    pjResourceBaseline7Cost = 205521299,
    pjResourceBaseline7Start = 205521304,
    pjResourceBaseline7Finish = 205521305,
    pjResourceBaseline8Work = 205521308,
    pjResourceBaseline8Cost = 205521309,
    pjResourceBaseline8Start = 205521314,
    pjResourceBaseline8Finish = 205521315,
    pjResourceBaseline9Work = 205521318,
    pjResourceBaseline9Cost = 205521319,
    pjResourceBaseline9Start = 205521324,
    pjResourceBaseline9Finish = 205521325,
    pjResourceBaseline10Work = 205521328,
    pjResourceBaseline10Cost = 205521329,
    pjResourceBaseline10Start = 205521334,
    pjResourceBaseline10Finish = 205521335,
    pjResourceEnterpriseUniqueID = 205521339,
    pjResourceEnterpriseCost1 = 205521342,
    pjResourceEnterpriseCost2 = 205521343,
    pjResourceEnterpriseCost3 = 205521344,
    pjResourceEnterpriseCost4 = 205521345,
    pjResourceEnterpriseCost5 = 205521346,
    pjResourceEnterpriseCost6 = 205521347,
    pjResourceEnterpriseCost7 = 205521348,
    pjResourceEnterpriseCost8 = 205521349,
    pjResourceEnterpriseCost9 = 205521350,
    pjResourceEnterpriseCost10 = 205521351,
    pjResourceEnterpriseDate1 = 205521352,
    pjResourceEnterpriseDate2 = 205521353,
    pjResourceEnterpriseDate3 = 205521354,
    pjResourceEnterpriseDate4 = 205521355,
    pjResourceEnterpriseDate5 = 205521356,
    pjResourceEnterpriseDate6 = 205521357,
    pjResourceEnterpriseDate7 = 205521358,
    pjResourceEnterpriseDate8 = 205521359,
    pjResourceEnterpriseDate9 = 205521360,
    pjResourceEnterpriseDate10 = 205521361,
    pjResourceEnterpriseDate11 = 205521362,
    pjResourceEnterpriseDate12 = 205521363,
    pjResourceEnterpriseDate13 = 205521364,
    pjResourceEnterpriseDate14 = 205521365,
    pjResourceEnterpriseDate15 = 205521366,
    pjResourceEnterpriseDate16 = 205521367,
    pjResourceEnterpriseDate17 = 205521368,
    pjResourceEnterpriseDate18 = 205521369,
    pjResourceEnterpriseDate19 = 205521370,
    pjResourceEnterpriseDate20 = 205521371,
    pjResourceEnterpriseDate21 = 205521372,
    pjResourceEnterpriseDate22 = 205521373,
    pjResourceEnterpriseDate23 = 205521374,
    pjResourceEnterpriseDate24 = 205521375,
    pjResourceEnterpriseDate25 = 205521376,
    pjResourceEnterpriseDate26 = 205521377,
    pjResourceEnterpriseDate27 = 205521378,
    pjResourceEnterpriseDate28 = 205521379,
    pjResourceEnterpriseDate29 = 205521380,
    pjResourceEnterpriseDate30 = 205521381,
    pjResourceEnterpriseDuration1 = 205521382,
    pjResourceEnterpriseDuration2 = 205521383,
    pjResourceEnterpriseDuration3 = 205521384,
    pjResourceEnterpriseDuration4 = 205521385,
    pjResourceEnterpriseDuration5 = 205521386,
    pjResourceEnterpriseDuration6 = 205521387,
    pjResourceEnterpriseDuration7 = 205521388,
    pjResourceEnterpriseDuration8 = 205521389,
    pjResourceEnterpriseDuration9 = 205521390,
    pjResourceEnterpriseDuration10 = 205521391,
    pjResourceEnterpriseFlag1 = 205521402,
    pjResourceEnterpriseFlag2 = 205521403,
    pjResourceEnterpriseFlag3 = 205521404,
    pjResourceEnterpriseFlag4 = 205521405,
    pjResourceEnterpriseFlag5 = 205521406,
    pjResourceEnterpriseFlag6 = 205521407,
    pjResourceEnterpriseFlag7 = 205521408,
    pjResourceEnterpriseFlag8 = 205521409,
    pjResourceEnterpriseFlag9 = 205521410,
    pjResourceEnterpriseFlag10 = 205521411,
    pjResourceEnterpriseFlag11 = 205521412,
    pjResourceEnterpriseFlag12 = 205521413,
    pjResourceEnterpriseFlag13 = 205521414,
    pjResourceEnterpriseFlag14 = 205521415,
    pjResourceEnterpriseFlag15 = 205521416,
    pjResourceEnterpriseFlag16 = 205521417,
    pjResourceEnterpriseFlag17 = 205521418,
    pjResourceEnterpriseFlag18 = 205521419,
    pjResourceEnterpriseFlag19 = 205521420,
    pjResourceEnterpriseFlag20 = 205521421,
    pjResourceEnterpriseNumber1 = 205521442,
    pjResourceEnterpriseNumber2 = 205521443,
    pjResourceEnterpriseNumber3 = 205521444,
    pjResourceEnterpriseNumber4 = 205521445,
    pjResourceEnterpriseNumber5 = 205521446,
    pjResourceEnterpriseNumber6 = 205521447,
    pjResourceEnterpriseNumber7 = 205521448,
    pjResourceEnterpriseNumber8 = 205521449,
    pjResourceEnterpriseNumber9 = 205521450,
    pjResourceEnterpriseNumber10 = 205521451,
    pjResourceEnterpriseNumber11 = 205521452,
    pjResourceEnterpriseNumber12 = 205521453,
    pjResourceEnterpriseNumber13 = 205521454,
    pjResourceEnterpriseNumber14 = 205521455,
    pjResourceEnterpriseNumber15 = 205521456,
    pjResourceEnterpriseNumber16 = 205521457,
    pjResourceEnterpriseNumber17 = 205521458,
    pjResourceEnterpriseNumber18 = 205521459,
    pjResourceEnterpriseNumber19 = 205521460,
    pjResourceEnterpriseNumber20 = 205521461,
    pjResourceEnterpriseNumber21 = 205521462,
    pjResourceEnterpriseNumber22 = 205521463,
    pjResourceEnterpriseNumber23 = 205521464,
    pjResourceEnterpriseNumber24 = 205521465,
    pjResourceEnterpriseNumber25 = 205521466,
    pjResourceEnterpriseNumber26 = 205521467,
    pjResourceEnterpriseNumber27 = 205521468,
    pjResourceEnterpriseNumber28 = 205521469,
    pjResourceEnterpriseNumber29 = 205521470,
    pjResourceEnterpriseNumber30 = 205521471,
    pjResourceEnterpriseNumber31 = 205521472,
    pjResourceEnterpriseNumber32 = 205521473,
    pjResourceEnterpriseNumber33 = 205521474,
    pjResourceEnterpriseNumber34 = 205521475,
    pjResourceEnterpriseNumber35 = 205521476,
    pjResourceEnterpriseNumber36 = 205521477,
    pjResourceEnterpriseNumber37 = 205521478,
    pjResourceEnterpriseNumber38 = 205521479,
    pjResourceEnterpriseNumber39 = 205521480,
    pjResourceEnterpriseNumber40 = 205521481,
    pjResourceEnterpriseOutlineCode1 = 205521482,
    pjResourceEnterpriseOutlineCode2 = 205521484,
    pjResourceEnterpriseOutlineCode3 = 205521486,
    pjResourceEnterpriseOutlineCode4 = 205521488,
    pjResourceEnterpriseOutlineCode5 = 205521490,
    pjResourceEnterpriseOutlineCode6 = 205521492,
    pjResourceEnterpriseOutlineCode7 = 205521494,
    pjResourceEnterpriseOutlineCode8 = 205521496,
    pjResourceEnterpriseOutlineCode9 = 205521498,
    pjResourceEnterpriseOutlineCode10 = 205521500,
    pjResourceEnterpriseOutlineCode11 = 205521502,
    pjResourceEnterpriseOutlineCode12 = 205521504,
    pjResourceEnterpriseOutlineCode13 = 205521506,
    pjResourceEnterpriseOutlineCode14 = 205521508,
    pjResourceEnterpriseOutlineCode15 = 205521510,
    pjResourceEnterpriseOutlineCode16 = 205521512,
    pjResourceEnterpriseOutlineCode17 = 205521514,
    pjResourceEnterpriseOutlineCode18 = 205521516,
    pjResourceEnterpriseOutlineCode19 = 205521518,
    pjResourceEnterpriseOutlineCode20 = 205521520,
    pjResourceEnterpriseOutlineCode21 = 205521522,
    pjResourceEnterpriseOutlineCode22 = 205521524,
    pjResourceEnterpriseOutlineCode23 = 205521526,
    pjResourceEnterpriseOutlineCode24 = 205521528,
    pjResourceEnterpriseOutlineCode25 = 205521530,
    pjResourceEnterpriseOutlineCode26 = 205521532,
    pjResourceEnterpriseOutlineCode27 = 205521534,
    pjResourceEnterpriseOutlineCode28 = 205521536,
    pjResourceEnterpriseOutlineCode29 = 205521538,
    pjResourceEnterpriseRBS = 205521540,
    pjResourceEnterpriseText1 = 205521542,
    pjResourceEnterpriseText2 = 205521543,
    pjResourceEnterpriseText3 = 205521544,
    pjResourceEnterpriseText4 = 205521545,
    pjResourceEnterpriseText5 = 205521546,
    pjResourceEnterpriseText6 = 205521547,
    pjResourceEnterpriseText7 = 205521548,
    pjResourceEnterpriseText8 = 205521549,
    pjResourceEnterpriseText9 = 205521550,
    pjResourceEnterpriseText10 = 205521551,
    pjResourceEnterpriseText11 = 205521552,
    pjResourceEnterpriseText12 = 205521553,
    pjResourceEnterpriseText13 = 205521554,
    pjResourceEnterpriseText14 = 205521555,
    pjResourceEnterpriseText15 = 205521556,
    pjResourceEnterpriseText16 = 205521557,
    pjResourceEnterpriseText17 = 205521558,
    pjResourceEnterpriseText18 = 205521559,
    pjResourceEnterpriseText19 = 205521560,
    pjResourceEnterpriseText20 = 205521561,
    pjResourceEnterpriseText21 = 205521562,
    pjResourceEnterpriseText22 = 205521563,
    pjResourceEnterpriseText23 = 205521564,
    pjResourceEnterpriseText24 = 205521565,
    pjResourceEnterpriseText25 = 205521566,
    pjResourceEnterpriseText26 = 205521567,
    pjResourceEnterpriseText27 = 205521568,
    pjResourceEnterpriseText28 = 205521569,
    pjResourceEnterpriseText29 = 205521570,
    pjResourceEnterpriseText30 = 205521571,
    pjResourceEnterpriseText31 = 205521572,
    pjResourceEnterpriseText32 = 205521573,
    pjResourceEnterpriseText33 = 205521574,
    pjResourceEnterpriseText34 = 205521575,
    pjResourceEnterpriseText35 = 205521576,
    pjResourceEnterpriseText36 = 205521577,
    pjResourceEnterpriseText37 = 205521578,
    pjResourceEnterpriseText38 = 205521579,
    pjResourceEnterpriseText39 = 205521580,
    pjResourceEnterpriseText40 = 205521581,
    pjResourceEnterpriseGeneric = 205521582,
    pjResourceEnterpriseBaseCalendar = 205521583,
    pjResourceEnterpriseRequiredValues = 205521584,
    pjResourceEnterpriseNameUsed = 205521585,
    pjResourceDemandedRequested = 205521586,
    pjResourceEnterprise = 205521587,
    pjResourceEnterpriseIsCheckedOut = 205521588,
    pjResourceEnterpriseCheckedOutBy = 205521589,
    pjResourceEnterpriseLastModifiedDate = 205521590,
    pjResourceEnterpriseTeamMember = 205521591,
    pjResourceEnterpriseInactive = 205521592,
    pjResourceBookingType = 205521595,
    pjResourceEnterpriseMultiValue20 = 205521596,
    pjResourceEnterpriseMultiValue21 = 205521598,
    pjResourceEnterpriseMultiValue22 = 205521600,
    pjResourceEnterpriseMultiValue23 = 205521602,
    pjResourceEnterpriseMultiValue24 = 205521604,
    pjResourceEnterpriseMultiValue25 = 205521606,
    pjResourceEnterpriseMultiValue26 = 205521608,
    pjResourceEnterpriseMultiValue27 = 205521610,
    pjResourceEnterpriseMultiValue28 = 205521612,
    pjResourceEnterpriseMultiValue29 = 205521614,
    pjResourceActualWorkProtected = 205521616,
    pjResourceActualOvertimeWorkProtected = 205521617,
    pjResourceCreated = 205521622,
    pjResourceGuid = 205521624,
    pjResourceCalendarGuid = 205521625,
    pjResourceErrorMessage = 205521634,
    pjResourceDefaultAssignmentOwner = 205521636,
    pjResourceBudget = 205521648,
    pjResourceBudgetWork = 205521649,
    pjResourceBudgetCost = 205521650,
    pjImportResource = 205521651,
    pjResourceBaselineBudgetWork = 205521652,
    pjResourceBaselineBudgetCost = 205521653,
    pjResourceBaseline1BudgetWork = 205521656,
    pjResourceBaseline1BudgetCost = 205521657,
    pjResourceBaseline2BudgetWork = 205521660,
    pjResourceBaseline2BudgetCost = 205521661,
    pjResourceBaseline3BudgetWork = 205521664,
    pjResourceBaseline3BudgetCost = 205521665,
    pjResourceBaseline4BudgetWork = 205521668,
    pjResourceBaseline4BudgetCost = 205521669,
    pjResourceBaseline5BudgetWork = 205521672,
    pjResourceBaseline5BudgetCost = 205521673,
    pjResourceBaseline6BudgetWork = 205521676,
    pjResourceBaseline6BudgetCost = 205521677,
    pjResourceBaseline7BudgetWork = 205521680,
    pjResourceBaseline7BudgetCost = 205521681,
    pjResourceBaseline8BudgetWork = 205521684,
    pjResourceBaseline8BudgetCost = 205521685,
    pjResourceBaseline9BudgetWork = 205521688,
    pjResourceBaseline9BudgetCost = 205521689,
    pjResourceBaseline10BudgetWork = 205521692,
    pjResourceBaseline10BudgetCost = 205521693,
    pjResourceIsTeam = 205521696,
    pjResourceCostCenter = 205521697,
    pjTaskDelay = 188743700
};

enum __declspec(uuid("ebf1c080-400e-11d0-ba3f-00a0c905437f"))
PjCustomField
{
    pjCustomTaskCost1 = 188743786,
    pjCustomTaskCost2 = 188743787,
    pjCustomTaskCost3 = 188743788,
    pjCustomTaskCost4 = 188743938,
    pjCustomTaskCost5 = 188743939,
    pjCustomTaskCost6 = 188743940,
    pjCustomTaskCost7 = 188743941,
    pjCustomTaskCost8 = 188743942,
    pjCustomTaskCost9 = 188743943,
    pjCustomTaskCost10 = 188743944,
    pjCustomTaskDate1 = 188743945,
    pjCustomTaskDate2 = 188743946,
    pjCustomTaskDate3 = 188743947,
    pjCustomTaskDate4 = 188743948,
    pjCustomTaskDate5 = 188743949,
    pjCustomTaskDate6 = 188743950,
    pjCustomTaskDate7 = 188743951,
    pjCustomTaskDate8 = 188743952,
    pjCustomTaskDate9 = 188743953,
    pjCustomTaskDate10 = 188743954,
    pjCustomTaskDuration1 = 188743783,
    pjCustomTaskDuration2 = 188743784,
    pjCustomTaskDuration3 = 188743785,
    pjCustomTaskDuration4 = 188743955,
    pjCustomTaskDuration5 = 188743956,
    pjCustomTaskDuration6 = 188743957,
    pjCustomTaskDuration7 = 188743958,
    pjCustomTaskDuration8 = 188743959,
    pjCustomTaskDuration9 = 188743960,
    pjCustomTaskDuration10 = 188743961,
    pjCustomTaskFinish1 = 188743733,
    pjCustomTaskFinish2 = 188743736,
    pjCustomTaskFinish3 = 188743739,
    pjCustomTaskFinish4 = 188743742,
    pjCustomTaskFinish5 = 188743745,
    pjCustomTaskFinish6 = 188743963,
    pjCustomTaskFinish7 = 188743965,
    pjCustomTaskFinish8 = 188743967,
    pjCustomTaskFinish9 = 188743969,
    pjCustomTaskFinish10 = 188743971,
    pjCustomTaskFlag1 = 188743752,
    pjCustomTaskFlag10 = 188743761,
    pjCustomTaskFlag2 = 188743753,
    pjCustomTaskFlag3 = 188743754,
    pjCustomTaskFlag4 = 188743755,
    pjCustomTaskFlag5 = 188743756,
    pjCustomTaskFlag6 = 188743757,
    pjCustomTaskFlag7 = 188743758,
    pjCustomTaskFlag8 = 188743759,
    pjCustomTaskFlag9 = 188743760,
    pjCustomTaskFlag11 = 188743972,
    pjCustomTaskFlag12 = 188743973,
    pjCustomTaskFlag13 = 188743974,
    pjCustomTaskFlag14 = 188743975,
    pjCustomTaskFlag15 = 188743976,
    pjCustomTaskFlag16 = 188743977,
    pjCustomTaskFlag17 = 188743978,
    pjCustomTaskFlag18 = 188743979,
    pjCustomTaskFlag19 = 188743980,
    pjCustomTaskFlag20 = 188743981,
    pjCustomTaskNumber1 = 188743767,
    pjCustomTaskNumber2 = 188743768,
    pjCustomTaskNumber3 = 188743769,
    pjCustomTaskNumber4 = 188743770,
    pjCustomTaskNumber5 = 188743771,
    pjCustomTaskNumber6 = 188743982,
    pjCustomTaskNumber7 = 188743983,
    pjCustomTaskNumber8 = 188743984,
    pjCustomTaskNumber9 = 188743985,
    pjCustomTaskNumber10 = 188743986,
    pjCustomTaskNumber11 = 188743987,
    pjCustomTaskNumber12 = 188743988,
    pjCustomTaskNumber13 = 188743989,
    pjCustomTaskNumber14 = 188743990,
    pjCustomTaskNumber15 = 188743991,
    pjCustomTaskNumber16 = 188743992,
    pjCustomTaskNumber17 = 188743993,
    pjCustomTaskNumber18 = 188743994,
    pjCustomTaskNumber19 = 188743995,
    pjCustomTaskNumber20 = 188743996,
    pjCustomTaskOutlineCode1 = 188744096,
    pjCustomTaskOutlineCode2 = 188744098,
    pjCustomTaskOutlineCode3 = 188744100,
    pjCustomTaskOutlineCode4 = 188744102,
    pjCustomTaskOutlineCode5 = 188744104,
    pjCustomTaskOutlineCode6 = 188744106,
    pjCustomTaskOutlineCode7 = 188744108,
    pjCustomTaskOutlineCode8 = 188744110,
    pjCustomTaskOutlineCode9 = 188744112,
    pjCustomTaskOutlineCode10 = 188744114,
    pjCustomTaskStart1 = 188743732,
    pjCustomTaskStart2 = 188743735,
    pjCustomTaskStart3 = 188743738,
    pjCustomTaskStart4 = 188743741,
    pjCustomTaskStart5 = 188743744,
    pjCustomTaskStart6 = 188743962,
    pjCustomTaskStart7 = 188743964,
    pjCustomTaskStart8 = 188743966,
    pjCustomTaskStart9 = 188743968,
    pjCustomTaskStart10 = 188743970,
    pjCustomTaskText1 = 188743731,
    pjCustomTaskText10 = 188743750,
    pjCustomTaskText2 = 188743734,
    pjCustomTaskText3 = 188743737,
    pjCustomTaskText4 = 188743740,
    pjCustomTaskText5 = 188743743,
    pjCustomTaskText6 = 188743746,
    pjCustomTaskText7 = 188743747,
    pjCustomTaskText8 = 188743748,
    pjCustomTaskText9 = 188743749,
    pjCustomTaskText11 = 188743997,
    pjCustomTaskText12 = 188743998,
    pjCustomTaskText13 = 188743999,
    pjCustomTaskText14 = 188744000,
    pjCustomTaskText15 = 188744001,
    pjCustomTaskText16 = 188744002,
    pjCustomTaskText17 = 188744003,
    pjCustomTaskText18 = 188744004,
    pjCustomTaskText19 = 188744005,
    pjCustomTaskText20 = 188744006,
    pjCustomTaskText21 = 188744007,
    pjCustomTaskText22 = 188744008,
    pjCustomTaskText23 = 188744009,
    pjCustomTaskText24 = 188744010,
    pjCustomTaskText25 = 188744011,
    pjCustomTaskText26 = 188744012,
    pjCustomTaskText27 = 188744013,
    pjCustomTaskText28 = 188744014,
    pjCustomTaskText29 = 188744015,
    pjCustomTaskText30 = 188744016,
    pjCustomResourceText1 = 205520904,
    pjCustomResourceText2 = 205520905,
    pjCustomResourceText3 = 205520926,
    pjCustomResourceText4 = 205520927,
    pjCustomResourceText5 = 205520928,
    pjCustomResourceText6 = 205520993,
    pjCustomResourceText7 = 205520994,
    pjCustomResourceText8 = 205520995,
    pjCustomResourceText9 = 205520996,
    pjCustomResourceText10 = 205520997,
    pjCustomResourceText11 = 205521121,
    pjCustomResourceText12 = 205521122,
    pjCustomResourceText13 = 205521123,
    pjCustomResourceText14 = 205521124,
    pjCustomResourceText15 = 205521125,
    pjCustomResourceText16 = 205521126,
    pjCustomResourceText17 = 205521127,
    pjCustomResourceText18 = 205521128,
    pjCustomResourceText19 = 205521129,
    pjCustomResourceText20 = 205521130,
    pjCustomResourceText21 = 205521131,
    pjCustomResourceText22 = 205521132,
    pjCustomResourceText23 = 205521133,
    pjCustomResourceText24 = 205521134,
    pjCustomResourceText25 = 205521135,
    pjCustomResourceText26 = 205521136,
    pjCustomResourceText27 = 205521137,
    pjCustomResourceText28 = 205521138,
    pjCustomResourceText29 = 205521139,
    pjCustomResourceText30 = 205521140,
    pjCustomResourceStart1 = 205520998,
    pjCustomResourceStart2 = 205520999,
    pjCustomResourceStart3 = 205521000,
    pjCustomResourceStart4 = 205521001,
    pjCustomResourceStart5 = 205521002,
    pjCustomResourceStart6 = 205521116,
    pjCustomResourceStart7 = 205521117,
    pjCustomResourceStart8 = 205521118,
    pjCustomResourceStart9 = 205521119,
    pjCustomResourceStart10 = 205521120,
    pjCustomResourceFinish1 = 205521003,
    pjCustomResourceFinish2 = 205521004,
    pjCustomResourceFinish3 = 205521005,
    pjCustomResourceFinish4 = 205521006,
    pjCustomResourceFinish5 = 205521007,
    pjCustomResourceFinish6 = 205521086,
    pjCustomResourceFinish7 = 205521087,
    pjCustomResourceFinish8 = 205521088,
    pjCustomResourceFinish9 = 205521089,
    pjCustomResourceFinish10 = 205521090,
    pjCustomResourceNumber1 = 205521008,
    pjCustomResourceNumber2 = 205521009,
    pjCustomResourceNumber3 = 205521010,
    pjCustomResourceNumber4 = 205521011,
    pjCustomResourceNumber5 = 205521012,
    pjCustomResourceNumber6 = 205521101,
    pjCustomResourceNumber7 = 205521102,
    pjCustomResourceNumber8 = 205521103,
    pjCustomResourceNumber9 = 205521104,
    pjCustomResourceNumber10 = 205521105,
    pjCustomResourceNumber11 = 205521106,
    pjCustomResourceNumber12 = 205521107,
    pjCustomResourceNumber13 = 205521108,
    pjCustomResourceNumber14 = 205521109,
    pjCustomResourceNumber15 = 205521110,
    pjCustomResourceNumber16 = 205521111,
    pjCustomResourceNumber17 = 205521112,
    pjCustomResourceNumber18 = 205521113,
    pjCustomResourceNumber19 = 205521114,
    pjCustomResourceNumber20 = 205521115,
    pjCustomResourceDuration1 = 205521013,
    pjCustomResourceDuration2 = 205521014,
    pjCustomResourceDuration3 = 205521015,
    pjCustomResourceDuration4 = 205521079,
    pjCustomResourceDuration5 = 205521080,
    pjCustomResourceDuration6 = 205521081,
    pjCustomResourceDuration7 = 205521082,
    pjCustomResourceDuration8 = 205521083,
    pjCustomResourceDuration9 = 205521084,
    pjCustomResourceDuration10 = 205521085,
    pjCustomResourceCost1 = 205521019,
    pjCustomResourceCost2 = 205521020,
    pjCustomResourceCost3 = 205521021,
    pjCustomResourceCost4 = 205521062,
    pjCustomResourceCost5 = 205521063,
    pjCustomResourceCost6 = 205521064,
    pjCustomResourceCost7 = 205521065,
    pjCustomResourceCost8 = 205521066,
    pjCustomResourceCost9 = 205521067,
    pjCustomResourceCost10 = 205521068,
    pjCustomResourceFlag10 = 205521022,
    pjCustomResourceFlag1 = 205521023,
    pjCustomResourceFlag2 = 205521024,
    pjCustomResourceFlag3 = 205521025,
    pjCustomResourceFlag4 = 205521026,
    pjCustomResourceFlag5 = 205521027,
    pjCustomResourceFlag6 = 205521028,
    pjCustomResourceFlag7 = 205521029,
    pjCustomResourceFlag8 = 205521030,
    pjCustomResourceFlag9 = 205521031,
    pjCustomResourceFlag11 = 205521091,
    pjCustomResourceFlag12 = 205521092,
    pjCustomResourceFlag13 = 205521093,
    pjCustomResourceFlag14 = 205521094,
    pjCustomResourceFlag15 = 205521095,
    pjCustomResourceFlag16 = 205521096,
    pjCustomResourceFlag17 = 205521097,
    pjCustomResourceFlag18 = 205521098,
    pjCustomResourceFlag19 = 205521099,
    pjCustomResourceFlag20 = 205521100,
    pjCustomResourceDate1 = 205521069,
    pjCustomResourceDate2 = 205521070,
    pjCustomResourceDate3 = 205521071,
    pjCustomResourceDate4 = 205521072,
    pjCustomResourceDate5 = 205521073,
    pjCustomResourceDate6 = 205521074,
    pjCustomResourceDate7 = 205521075,
    pjCustomResourceDate8 = 205521076,
    pjCustomResourceDate9 = 205521077,
    pjCustomResourceDate10 = 205521078,
    pjCustomResourceOutlineCode1 = 205521174,
    pjCustomResourceOutlineCode2 = 205521176,
    pjCustomResourceOutlineCode3 = 205521178,
    pjCustomResourceOutlineCode4 = 205521180,
    pjCustomResourceOutlineCode5 = 205521182,
    pjCustomResourceOutlineCode6 = 205521184,
    pjCustomResourceOutlineCode7 = 205521186,
    pjCustomResourceOutlineCode8 = 205521188,
    pjCustomResourceOutlineCode9 = 205521190,
    pjCustomResourceOutlineCode10 = 205521192,
    pjCustomProjectEnterpriseCost1 = 188744529,
    pjCustomProjectEnterpriseCost2 = 188744530,
    pjCustomProjectEnterpriseCost3 = 188744531,
    pjCustomProjectEnterpriseCost4 = 188744532,
    pjCustomProjectEnterpriseCost5 = 188744533,
    pjCustomProjectEnterpriseCost6 = 188744534,
    pjCustomProjectEnterpriseCost7 = 188744535,
    pjCustomProjectEnterpriseCost8 = 188744536,
    pjCustomProjectEnterpriseCost9 = 188744537,
    pjCustomProjectEnterpriseCost10 = 188744538,
    pjCustomProjectEnterpriseDate1 = 188744539,
    pjCustomProjectEnterpriseDate2 = 188744540,
    pjCustomProjectEnterpriseDate3 = 188744541,
    pjCustomProjectEnterpriseDate4 = 188744542,
    pjCustomProjectEnterpriseDate5 = 188744543,
    pjCustomProjectEnterpriseDate6 = 188744544,
    pjCustomProjectEnterpriseDate7 = 188744545,
    pjCustomProjectEnterpriseDate8 = 188744546,
    pjCustomProjectEnterpriseDate9 = 188744547,
    pjCustomProjectEnterpriseDate10 = 188744548,
    pjCustomProjectEnterpriseDate11 = 188744549,
    pjCustomProjectEnterpriseDate12 = 188744550,
    pjCustomProjectEnterpriseDate13 = 188744551,
    pjCustomProjectEnterpriseDate14 = 188744552,
    pjCustomProjectEnterpriseDate15 = 188744553,
    pjCustomProjectEnterpriseDate16 = 188744554,
    pjCustomProjectEnterpriseDate17 = 188744555,
    pjCustomProjectEnterpriseDate18 = 188744556,
    pjCustomProjectEnterpriseDate19 = 188744557,
    pjCustomProjectEnterpriseDate20 = 188744558,
    pjCustomProjectEnterpriseDate21 = 188744559,
    pjCustomProjectEnterpriseDate22 = 188744560,
    pjCustomProjectEnterpriseDate23 = 188744561,
    pjCustomProjectEnterpriseDate24 = 188744562,
    pjCustomProjectEnterpriseDate25 = 188744563,
    pjCustomProjectEnterpriseDate26 = 188744564,
    pjCustomProjectEnterpriseDate27 = 188744565,
    pjCustomProjectEnterpriseDate28 = 188744566,
    pjCustomProjectEnterpriseDate29 = 188744567,
    pjCustomProjectEnterpriseDate30 = 188744568,
    pjCustomProjectEnterpriseDuration1 = 188744569,
    pjCustomProjectEnterpriseDuration2 = 188744570,
    pjCustomProjectEnterpriseDuration3 = 188744571,
    pjCustomProjectEnterpriseDuration4 = 188744572,
    pjCustomProjectEnterpriseDuration5 = 188744573,
    pjCustomProjectEnterpriseDuration6 = 188744574,
    pjCustomProjectEnterpriseDuration7 = 188744575,
    pjCustomProjectEnterpriseDuration8 = 188744576,
    pjCustomProjectEnterpriseDuration9 = 188744577,
    pjCustomProjectEnterpriseDuration10 = 188744578,
    pjCustomProjectEnterpriseOutlineCode1 = 188744589,
    pjCustomProjectEnterpriseOutlineCode2 = 188744590,
    pjCustomProjectEnterpriseOutlineCode3 = 188744591,
    pjCustomProjectEnterpriseOutlineCode4 = 188744592,
    pjCustomProjectEnterpriseOutlineCode5 = 188744593,
    pjCustomProjectEnterpriseOutlineCode6 = 188744594,
    pjCustomProjectEnterpriseOutlineCode7 = 188744595,
    pjCustomProjectEnterpriseOutlineCode8 = 188744596,
    pjCustomProjectEnterpriseOutlineCode9 = 188744597,
    pjCustomProjectEnterpriseOutlineCode10 = 188744598,
    pjCustomProjectEnterpriseOutlineCode11 = 188744599,
    pjCustomProjectEnterpriseOutlineCode12 = 188744600,
    pjCustomProjectEnterpriseOutlineCode13 = 188744601,
    pjCustomProjectEnterpriseOutlineCode14 = 188744602,
    pjCustomProjectEnterpriseOutlineCode15 = 188744603,
    pjCustomProjectEnterpriseOutlineCode16 = 188744604,
    pjCustomProjectEnterpriseOutlineCode17 = 188744605,
    pjCustomProjectEnterpriseOutlineCode18 = 188744606,
    pjCustomProjectEnterpriseOutlineCode19 = 188744607,
    pjCustomProjectEnterpriseOutlineCode20 = 188744608,
    pjCustomProjectEnterpriseOutlineCode21 = 188744609,
    pjCustomProjectEnterpriseOutlineCode22 = 188744610,
    pjCustomProjectEnterpriseOutlineCode23 = 188744611,
    pjCustomProjectEnterpriseOutlineCode24 = 188744612,
    pjCustomProjectEnterpriseOutlineCode25 = 188744613,
    pjCustomProjectEnterpriseOutlineCode26 = 188744614,
    pjCustomProjectEnterpriseOutlineCode27 = 188744615,
    pjCustomProjectEnterpriseOutlineCode28 = 188744616,
    pjCustomProjectEnterpriseOutlineCode29 = 188744617,
    pjCustomProjectEnterpriseOutlineCode30 = 188744618,
    pjCustomProjectEnterpriseFlag1 = 188744649,
    pjCustomProjectEnterpriseFlag2 = 188744650,
    pjCustomProjectEnterpriseFlag3 = 188744651,
    pjCustomProjectEnterpriseFlag4 = 188744652,
    pjCustomProjectEnterpriseFlag5 = 188744653,
    pjCustomProjectEnterpriseFlag6 = 188744654,
    pjCustomProjectEnterpriseFlag7 = 188744655,
    pjCustomProjectEnterpriseFlag8 = 188744656,
    pjCustomProjectEnterpriseFlag9 = 188744657,
    pjCustomProjectEnterpriseFlag10 = 188744658,
    pjCustomProjectEnterpriseFlag11 = 188744659,
    pjCustomProjectEnterpriseFlag12 = 188744660,
    pjCustomProjectEnterpriseFlag13 = 188744661,
    pjCustomProjectEnterpriseFlag14 = 188744662,
    pjCustomProjectEnterpriseFlag15 = 188744663,
    pjCustomProjectEnterpriseFlag16 = 188744664,
    pjCustomProjectEnterpriseFlag17 = 188744665,
    pjCustomProjectEnterpriseFlag18 = 188744666,
    pjCustomProjectEnterpriseFlag19 = 188744667,
    pjCustomProjectEnterpriseFlag20 = 188744668,
    pjCustomProjectEnterpriseNumber1 = 188744689,
    pjCustomProjectEnterpriseNumber2 = 188744690,
    pjCustomProjectEnterpriseNumber3 = 188744691,
    pjCustomProjectEnterpriseNumber4 = 188744692,
    pjCustomProjectEnterpriseNumber5 = 188744693,
    pjCustomProjectEnterpriseNumber6 = 188744694,
    pjCustomProjectEnterpriseNumber7 = 188744695,
    pjCustomProjectEnterpriseNumber8 = 188744696,
    pjCustomProjectEnterpriseNumber9 = 188744697,
    pjCustomProjectEnterpriseNumber10 = 188744698,
    pjCustomProjectEnterpriseNumber11 = 188744699,
    pjCustomProjectEnterpriseNumber12 = 188744700,
    pjCustomProjectEnterpriseNumber13 = 188744701,
    pjCustomProjectEnterpriseNumber14 = 188744702,
    pjCustomProjectEnterpriseNumber15 = 188744703,
    pjCustomProjectEnterpriseNumber16 = 188744704,
    pjCustomProjectEnterpriseNumber17 = 188744705,
    pjCustomProjectEnterpriseNumber18 = 188744706,
    pjCustomProjectEnterpriseNumber19 = 188744707,
    pjCustomProjectEnterpriseNumber20 = 188744708,
    pjCustomProjectEnterpriseNumber21 = 188744709,
    pjCustomProjectEnterpriseNumber22 = 188744710,
    pjCustomProjectEnterpriseNumber23 = 188744711,
    pjCustomProjectEnterpriseNumber24 = 188744712,
    pjCustomProjectEnterpriseNumber25 = 188744713,
    pjCustomProjectEnterpriseNumber26 = 188744714,
    pjCustomProjectEnterpriseNumber27 = 188744715,
    pjCustomProjectEnterpriseNumber28 = 188744716,
    pjCustomProjectEnterpriseNumber29 = 188744717,
    pjCustomProjectEnterpriseNumber30 = 188744718,
    pjCustomProjectEnterpriseNumber31 = 188744719,
    pjCustomProjectEnterpriseNumber32 = 188744720,
    pjCustomProjectEnterpriseNumber33 = 188744721,
    pjCustomProjectEnterpriseNumber34 = 188744722,
    pjCustomProjectEnterpriseNumber35 = 188744723,
    pjCustomProjectEnterpriseNumber36 = 188744724,
    pjCustomProjectEnterpriseNumber37 = 188744725,
    pjCustomProjectEnterpriseNumber38 = 188744726,
    pjCustomProjectEnterpriseNumber39 = 188744727,
    pjCustomProjectEnterpriseNumber40 = 188744728,
    pjCustomProjectEnterpriseText1 = 188744729,
    pjCustomProjectEnterpriseText2 = 188744730,
    pjCustomProjectEnterpriseText3 = 188744731,
    pjCustomProjectEnterpriseText4 = 188744732,
    pjCustomProjectEnterpriseText5 = 188744733,
    pjCustomProjectEnterpriseText6 = 188744734,
    pjCustomProjectEnterpriseText7 = 188744735,
    pjCustomProjectEnterpriseText8 = 188744736,
    pjCustomProjectEnterpriseText9 = 188744737,
    pjCustomProjectEnterpriseText10 = 188744738,
    pjCustomProjectEnterpriseText11 = 188744739,
    pjCustomProjectEnterpriseText12 = 188744740,
    pjCustomProjectEnterpriseText13 = 188744741,
    pjCustomProjectEnterpriseText14 = 188744742,
    pjCustomProjectEnterpriseText15 = 188744743,
    pjCustomProjectEnterpriseText16 = 188744744,
    pjCustomProjectEnterpriseText17 = 188744745,
    pjCustomProjectEnterpriseText18 = 188744746,
    pjCustomProjectEnterpriseText19 = 188744747,
    pjCustomProjectEnterpriseText20 = 188744748,
    pjCustomProjectEnterpriseText21 = 188744749,
    pjCustomProjectEnterpriseText22 = 188744750,
    pjCustomProjectEnterpriseText23 = 188744751,
    pjCustomProjectEnterpriseText24 = 188744752,
    pjCustomProjectEnterpriseText25 = 188744753,
    pjCustomProjectEnterpriseText26 = 188744754,
    pjCustomProjectEnterpriseText27 = 188744755,
    pjCustomProjectEnterpriseText28 = 188744756,
    pjCustomProjectEnterpriseText29 = 188744757,
    pjCustomProjectEnterpriseText30 = 188744758,
    pjCustomProjectEnterpriseText31 = 188744759,
    pjCustomProjectEnterpriseText32 = 188744760,
    pjCustomProjectEnterpriseText33 = 188744761,
    pjCustomProjectEnterpriseText34 = 188744762,
    pjCustomProjectEnterpriseText35 = 188744763,
    pjCustomProjectEnterpriseText36 = 188744764,
    pjCustomProjectEnterpriseText37 = 188744765,
    pjCustomProjectEnterpriseText38 = 188744766,
    pjCustomProjectEnterpriseText39 = 188744767,
    pjCustomProjectEnterpriseText40 = 188744768,
    pjCustomTaskEnterpriseCost1 = 188744279,
    pjCustomTaskEnterpriseCost2 = 188744280,
    pjCustomTaskEnterpriseCost3 = 188744281,
    pjCustomTaskEnterpriseCost4 = 188744282,
    pjCustomTaskEnterpriseCost5 = 188744283,
    pjCustomTaskEnterpriseCost6 = 188744284,
    pjCustomTaskEnterpriseCost7 = 188744285,
    pjCustomTaskEnterpriseCost8 = 188744286,
    pjCustomTaskEnterpriseCost9 = 188744287,
    pjCustomTaskEnterpriseCost10 = 188744288,
    pjCustomTaskEnterpriseDate1 = 188744289,
    pjCustomTaskEnterpriseDate2 = 188744290,
    pjCustomTaskEnterpriseDate3 = 188744291,
    pjCustomTaskEnterpriseDate4 = 188744292,
    pjCustomTaskEnterpriseDate5 = 188744293,
    pjCustomTaskEnterpriseDate6 = 188744294,
    pjCustomTaskEnterpriseDate7 = 188744295,
    pjCustomTaskEnterpriseDate8 = 188744296,
    pjCustomTaskEnterpriseDate9 = 188744297,
    pjCustomTaskEnterpriseDate10 = 188744298,
    pjCustomTaskEnterpriseDate11 = 188744299,
    pjCustomTaskEnterpriseDate12 = 188744300,
    pjCustomTaskEnterpriseDate13 = 188744301,
    pjCustomTaskEnterpriseDate14 = 188744302,
    pjCustomTaskEnterpriseDate15 = 188744303,
    pjCustomTaskEnterpriseDate16 = 188744304,
    pjCustomTaskEnterpriseDate17 = 188744305,
    pjCustomTaskEnterpriseDate18 = 188744306,
    pjCustomTaskEnterpriseDate19 = 188744307,
    pjCustomTaskEnterpriseDate20 = 188744308,
    pjCustomTaskEnterpriseDate21 = 188744309,
    pjCustomTaskEnterpriseDate22 = 188744310,
    pjCustomTaskEnterpriseDate23 = 188744311,
    pjCustomTaskEnterpriseDate24 = 188744312,
    pjCustomTaskEnterpriseDate25 = 188744313,
    pjCustomTaskEnterpriseDate26 = 188744314,
    pjCustomTaskEnterpriseDate27 = 188744315,
    pjCustomTaskEnterpriseDate28 = 188744316,
    pjCustomTaskEnterpriseDate29 = 188744317,
    pjCustomTaskEnterpriseDate30 = 188744318,
    pjCustomTaskEnterpriseDuration1 = 188744319,
    pjCustomTaskEnterpriseDuration2 = 188744320,
    pjCustomTaskEnterpriseDuration3 = 188744321,
    pjCustomTaskEnterpriseDuration4 = 188744322,
    pjCustomTaskEnterpriseDuration5 = 188744323,
    pjCustomTaskEnterpriseDuration6 = 188744324,
    pjCustomTaskEnterpriseDuration7 = 188744325,
    pjCustomTaskEnterpriseDuration8 = 188744326,
    pjCustomTaskEnterpriseDuration9 = 188744327,
    pjCustomTaskEnterpriseDuration10 = 188744328,
    pjCustomTaskEnterpriseOutlineCode1 = 188744419,
    pjCustomTaskEnterpriseOutlineCode2 = 188744421,
    pjCustomTaskEnterpriseOutlineCode3 = 188744423,
    pjCustomTaskEnterpriseOutlineCode4 = 188744425,
    pjCustomTaskEnterpriseOutlineCode5 = 188744427,
    pjCustomTaskEnterpriseOutlineCode6 = 188744429,
    pjCustomTaskEnterpriseOutlineCode7 = 188744431,
    pjCustomTaskEnterpriseOutlineCode8 = 188744433,
    pjCustomTaskEnterpriseOutlineCode9 = 188744435,
    pjCustomTaskEnterpriseOutlineCode10 = 188744437,
    pjCustomTaskEnterpriseOutlineCode11 = 188744439,
    pjCustomTaskEnterpriseOutlineCode12 = 188744441,
    pjCustomTaskEnterpriseOutlineCode13 = 188744443,
    pjCustomTaskEnterpriseOutlineCode14 = 188744445,
    pjCustomTaskEnterpriseOutlineCode15 = 188744447,
    pjCustomTaskEnterpriseOutlineCode16 = 188744449,
    pjCustomTaskEnterpriseOutlineCode17 = 188744451,
    pjCustomTaskEnterpriseOutlineCode18 = 188744453,
    pjCustomTaskEnterpriseOutlineCode19 = 188744455,
    pjCustomTaskEnterpriseOutlineCode20 = 188744457,
    pjCustomTaskEnterpriseOutlineCode21 = 188744459,
    pjCustomTaskEnterpriseOutlineCode22 = 188744461,
    pjCustomTaskEnterpriseOutlineCode23 = 188744463,
    pjCustomTaskEnterpriseOutlineCode24 = 188744465,
    pjCustomTaskEnterpriseOutlineCode25 = 188744467,
    pjCustomTaskEnterpriseOutlineCode26 = 188744469,
    pjCustomTaskEnterpriseOutlineCode27 = 188744471,
    pjCustomTaskEnterpriseOutlineCode28 = 188744473,
    pjCustomTaskEnterpriseOutlineCode29 = 188744475,
    pjCustomTaskEnterpriseOutlineCode30 = 188744477,
    pjCustomTaskEnterpriseFlag1 = 188744339,
    pjCustomTaskEnterpriseFlag2 = 188744340,
    pjCustomTaskEnterpriseFlag3 = 188744341,
    pjCustomTaskEnterpriseFlag4 = 188744342,
    pjCustomTaskEnterpriseFlag5 = 188744343,
    pjCustomTaskEnterpriseFlag6 = 188744344,
    pjCustomTaskEnterpriseFlag7 = 188744345,
    pjCustomTaskEnterpriseFlag8 = 188744346,
    pjCustomTaskEnterpriseFlag9 = 188744347,
    pjCustomTaskEnterpriseFlag10 = 188744348,
    pjCustomTaskEnterpriseFlag11 = 188744349,
    pjCustomTaskEnterpriseFlag12 = 188744350,
    pjCustomTaskEnterpriseFlag13 = 188744351,
    pjCustomTaskEnterpriseFlag14 = 188744352,
    pjCustomTaskEnterpriseFlag15 = 188744353,
    pjCustomTaskEnterpriseFlag16 = 188744354,
    pjCustomTaskEnterpriseFlag17 = 188744355,
    pjCustomTaskEnterpriseFlag18 = 188744356,
    pjCustomTaskEnterpriseFlag19 = 188744357,
    pjCustomTaskEnterpriseFlag20 = 188744358,
    pjCustomTaskEnterpriseNumber1 = 188744379,
    pjCustomTaskEnterpriseNumber2 = 188744380,
    pjCustomTaskEnterpriseNumber3 = 188744381,
    pjCustomTaskEnterpriseNumber4 = 188744382,
    pjCustomTaskEnterpriseNumber5 = 188744383,
    pjCustomTaskEnterpriseNumber6 = 188744384,
    pjCustomTaskEnterpriseNumber7 = 188744385,
    pjCustomTaskEnterpriseNumber8 = 188744386,
    pjCustomTaskEnterpriseNumber9 = 188744387,
    pjCustomTaskEnterpriseNumber10 = 188744388,
    pjCustomTaskEnterpriseNumber11 = 188744389,
    pjCustomTaskEnterpriseNumber12 = 188744390,
    pjCustomTaskEnterpriseNumber13 = 188744391,
    pjCustomTaskEnterpriseNumber14 = 188744392,
    pjCustomTaskEnterpriseNumber15 = 188744393,
    pjCustomTaskEnterpriseNumber16 = 188744394,
    pjCustomTaskEnterpriseNumber17 = 188744395,
    pjCustomTaskEnterpriseNumber18 = 188744396,
    pjCustomTaskEnterpriseNumber19 = 188744397,
    pjCustomTaskEnterpriseNumber20 = 188744398,
    pjCustomTaskEnterpriseNumber21 = 188744399,
    pjCustomTaskEnterpriseNumber22 = 188744400,
    pjCustomTaskEnterpriseNumber23 = 188744401,
    pjCustomTaskEnterpriseNumber24 = 188744402,
    pjCustomTaskEnterpriseNumber25 = 188744403,
    pjCustomTaskEnterpriseNumber26 = 188744404,
    pjCustomTaskEnterpriseNumber27 = 188744405,
    pjCustomTaskEnterpriseNumber28 = 188744406,
    pjCustomTaskEnterpriseNumber29 = 188744407,
    pjCustomTaskEnterpriseNumber30 = 188744408,
    pjCustomTaskEnterpriseNumber31 = 188744409,
    pjCustomTaskEnterpriseNumber32 = 188744410,
    pjCustomTaskEnterpriseNumber33 = 188744411,
    pjCustomTaskEnterpriseNumber34 = 188744412,
    pjCustomTaskEnterpriseNumber35 = 188744413,
    pjCustomTaskEnterpriseNumber36 = 188744414,
    pjCustomTaskEnterpriseNumber37 = 188744415,
    pjCustomTaskEnterpriseNumber38 = 188744416,
    pjCustomTaskEnterpriseNumber39 = 188744417,
    pjCustomTaskEnterpriseNumber40 = 188744418,
    pjCustomTaskEnterpriseText1 = 188744479,
    pjCustomTaskEnterpriseText2 = 188744480,
    pjCustomTaskEnterpriseText3 = 188744481,
    pjCustomTaskEnterpriseText4 = 188744482,
    pjCustomTaskEnterpriseText5 = 188744483,
    pjCustomTaskEnterpriseText6 = 188744484,
    pjCustomTaskEnterpriseText7 = 188744485,
    pjCustomTaskEnterpriseText8 = 188744486,
    pjCustomTaskEnterpriseText9 = 188744487,
    pjCustomTaskEnterpriseText10 = 188744488,
    pjCustomTaskEnterpriseText11 = 188744489,
    pjCustomTaskEnterpriseText12 = 188744490,
    pjCustomTaskEnterpriseText13 = 188744491,
    pjCustomTaskEnterpriseText14 = 188744492,
    pjCustomTaskEnterpriseText15 = 188744493,
    pjCustomTaskEnterpriseText16 = 188744494,
    pjCustomTaskEnterpriseText17 = 188744495,
    pjCustomTaskEnterpriseText18 = 188744496,
    pjCustomTaskEnterpriseText19 = 188744497,
    pjCustomTaskEnterpriseText20 = 188744498,
    pjCustomTaskEnterpriseText21 = 188744499,
    pjCustomTaskEnterpriseText22 = 188744500,
    pjCustomTaskEnterpriseText23 = 188744501,
    pjCustomTaskEnterpriseText24 = 188744502,
    pjCustomTaskEnterpriseText25 = 188744503,
    pjCustomTaskEnterpriseText26 = 188744504,
    pjCustomTaskEnterpriseText27 = 188744505,
    pjCustomTaskEnterpriseText28 = 188744506,
    pjCustomTaskEnterpriseText29 = 188744507,
    pjCustomTaskEnterpriseText30 = 188744508,
    pjCustomTaskEnterpriseText31 = 188744509,
    pjCustomTaskEnterpriseText32 = 188744510,
    pjCustomTaskEnterpriseText33 = 188744511,
    pjCustomTaskEnterpriseText34 = 188744512,
    pjCustomTaskEnterpriseText35 = 188744513,
    pjCustomTaskEnterpriseText36 = 188744514,
    pjCustomTaskEnterpriseText37 = 188744515,
    pjCustomTaskEnterpriseText38 = 188744516,
    pjCustomTaskEnterpriseText39 = 188744517,
    pjCustomTaskEnterpriseText40 = 188744518,
    pjCustomResourceEnterpriseCost1 = 205521342,
    pjCustomResourceEnterpriseCost2 = 205521343,
    pjCustomResourceEnterpriseCost3 = 205521344,
    pjCustomResourceEnterpriseCost4 = 205521345,
    pjCustomResourceEnterpriseCost5 = 205521346,
    pjCustomResourceEnterpriseCost6 = 205521347,
    pjCustomResourceEnterpriseCost7 = 205521348,
    pjCustomResourceEnterpriseCost8 = 205521349,
    pjCustomResourceEnterpriseCost9 = 205521350,
    pjCustomResourceEnterpriseCost10 = 205521351,
    pjCustomResourceEnterpriseDate1 = 205521352,
    pjCustomResourceEnterpriseDate2 = 205521353,
    pjCustomResourceEnterpriseDate3 = 205521354,
    pjCustomResourceEnterpriseDate4 = 205521355,
    pjCustomResourceEnterpriseDate5 = 205521356,
    pjCustomResourceEnterpriseDate6 = 205521357,
    pjCustomResourceEnterpriseDate7 = 205521358,
    pjCustomResourceEnterpriseDate8 = 205521359,
    pjCustomResourceEnterpriseDate9 = 205521360,
    pjCustomResourceEnterpriseDate10 = 205521361,
    pjCustomResourceEnterpriseDate11 = 205521362,
    pjCustomResourceEnterpriseDate12 = 205521363,
    pjCustomResourceEnterpriseDate13 = 205521364,
    pjCustomResourceEnterpriseDate14 = 205521365,
    pjCustomResourceEnterpriseDate15 = 205521366,
    pjCustomResourceEnterpriseDate16 = 205521367,
    pjCustomResourceEnterpriseDate17 = 205521368,
    pjCustomResourceEnterpriseDate18 = 205521369,
    pjCustomResourceEnterpriseDate19 = 205521370,
    pjCustomResourceEnterpriseDate20 = 205521371,
    pjCustomResourceEnterpriseDate21 = 205521372,
    pjCustomResourceEnterpriseDate22 = 205521373,
    pjCustomResourceEnterpriseDate23 = 205521374,
    pjCustomResourceEnterpriseDate24 = 205521375,
    pjCustomResourceEnterpriseDate25 = 205521376,
    pjCustomResourceEnterpriseDate26 = 205521377,
    pjCustomResourceEnterpriseDate27 = 205521378,
    pjCustomResourceEnterpriseDate28 = 205521379,
    pjCustomResourceEnterpriseDate29 = 205521380,
    pjCustomResourceEnterpriseDate30 = 205521381,
    pjCustomResourceEnterpriseDuration1 = 205521382,
    pjCustomResourceEnterpriseDuration2 = 205521383,
    pjCustomResourceEnterpriseDuration3 = 205521384,
    pjCustomResourceEnterpriseDuration4 = 205521385,
    pjCustomResourceEnterpriseDuration5 = 205521386,
    pjCustomResourceEnterpriseDuration6 = 205521387,
    pjCustomResourceEnterpriseDuration7 = 205521388,
    pjCustomResourceEnterpriseDuration8 = 205521389,
    pjCustomResourceEnterpriseDuration9 = 205521390,
    pjCustomResourceEnterpriseDuration10 = 205521391,
    pjCustomResourceEnterpriseOutlineCode1 = 205521482,
    pjCustomResourceEnterpriseOutlineCode2 = 205521484,
    pjCustomResourceEnterpriseOutlineCode3 = 205521486,
    pjCustomResourceEnterpriseOutlineCode4 = 205521488,
    pjCustomResourceEnterpriseOutlineCode5 = 205521490,
    pjCustomResourceEnterpriseOutlineCode6 = 205521492,
    pjCustomResourceEnterpriseOutlineCode7 = 205521494,
    pjCustomResourceEnterpriseOutlineCode8 = 205521496,
    pjCustomResourceEnterpriseOutlineCode9 = 205521498,
    pjCustomResourceEnterpriseOutlineCode10 = 205521500,
    pjCustomResourceEnterpriseOutlineCode11 = 205521502,
    pjCustomResourceEnterpriseOutlineCode12 = 205521504,
    pjCustomResourceEnterpriseOutlineCode13 = 205521506,
    pjCustomResourceEnterpriseOutlineCode14 = 205521508,
    pjCustomResourceEnterpriseOutlineCode15 = 205521510,
    pjCustomResourceEnterpriseOutlineCode16 = 205521512,
    pjCustomResourceEnterpriseOutlineCode17 = 205521514,
    pjCustomResourceEnterpriseOutlineCode18 = 205521516,
    pjCustomResourceEnterpriseOutlineCode19 = 205521518,
    pjCustomResourceEnterpriseOutlineCode20 = 205521520,
    pjCustomResourceEnterpriseOutlineCode21 = 205521522,
    pjCustomResourceEnterpriseOutlineCode22 = 205521524,
    pjCustomResourceEnterpriseOutlineCode23 = 205521526,
    pjCustomResourceEnterpriseOutlineCode24 = 205521528,
    pjCustomResourceEnterpriseOutlineCode25 = 205521530,
    pjCustomResourceEnterpriseOutlineCode26 = 205521532,
    pjCustomResourceEnterpriseOutlineCode27 = 205521534,
    pjCustomResourceEnterpriseOutlineCode28 = 205521536,
    pjCustomResourceEnterpriseOutlineCode29 = 205521538,
    pjCustomResourceEnterpriseRBS = 205521540,
    pjCustomResourceEnterpriseFlag1 = 205521402,
    pjCustomResourceEnterpriseFlag2 = 205521403,
    pjCustomResourceEnterpriseFlag3 = 205521404,
    pjCustomResourceEnterpriseFlag4 = 205521405,
    pjCustomResourceEnterpriseFlag5 = 205521406,
    pjCustomResourceEnterpriseFlag6 = 205521407,
    pjCustomResourceEnterpriseFlag7 = 205521408,
    pjCustomResourceEnterpriseFlag8 = 205521409,
    pjCustomResourceEnterpriseFlag9 = 205521410,
    pjCustomResourceEnterpriseFlag10 = 205521411,
    pjCustomResourceEnterpriseFlag11 = 205521412,
    pjCustomResourceEnterpriseFlag12 = 205521413,
    pjCustomResourceEnterpriseFlag13 = 205521414,
    pjCustomResourceEnterpriseFlag14 = 205521415,
    pjCustomResourceEnterpriseFlag15 = 205521416,
    pjCustomResourceEnterpriseFlag16 = 205521417,
    pjCustomResourceEnterpriseFlag17 = 205521418,
    pjCustomResourceEnterpriseFlag18 = 205521419,
    pjCustomResourceEnterpriseFlag19 = 205521420,
    pjCustomResourceEnterpriseFlag20 = 205521421,
    pjCustomResourceEnterpriseNumber1 = 205521442,
    pjCustomResourceEnterpriseNumber2 = 205521443,
    pjCustomResourceEnterpriseNumber3 = 205521444,
    pjCustomResourceEnterpriseNumber4 = 205521445,
    pjCustomResourceEnterpriseNumber5 = 205521446,
    pjCustomResourceEnterpriseNumber6 = 205521447,
    pjCustomResourceEnterpriseNumber7 = 205521448,
    pjCustomResourceEnterpriseNumber8 = 205521449,
    pjCustomResourceEnterpriseNumber9 = 205521450,
    pjCustomResourceEnterpriseNumber10 = 205521451,
    pjCustomResourceEnterpriseNumber11 = 205521452,
    pjCustomResourceEnterpriseNumber12 = 205521453,
    pjCustomResourceEnterpriseNumber13 = 205521454,
    pjCustomResourceEnterpriseNumber14 = 205521455,
    pjCustomResourceEnterpriseNumber15 = 205521456,
    pjCustomResourceEnterpriseNumber16 = 205521457,
    pjCustomResourceEnterpriseNumber17 = 205521458,
    pjCustomResourceEnterpriseNumber18 = 205521459,
    pjCustomResourceEnterpriseNumber19 = 205521460,
    pjCustomResourceEnterpriseNumber20 = 205521461,
    pjCustomResourceEnterpriseNumber21 = 205521462,
    pjCustomResourceEnterpriseNumber22 = 205521463,
    pjCustomResourceEnterpriseNumber23 = 205521464,
    pjCustomResourceEnterpriseNumber24 = 205521465,
    pjCustomResourceEnterpriseNumber25 = 205521466,
    pjCustomResourceEnterpriseNumber26 = 205521467,
    pjCustomResourceEnterpriseNumber27 = 205521468,
    pjCustomResourceEnterpriseNumber28 = 205521469,
    pjCustomResourceEnterpriseNumber29 = 205521470,
    pjCustomResourceEnterpriseNumber30 = 205521471,
    pjCustomResourceEnterpriseNumber31 = 205521472,
    pjCustomResourceEnterpriseNumber32 = 205521473,
    pjCustomResourceEnterpriseNumber33 = 205521474,
    pjCustomResourceEnterpriseNumber34 = 205521475,
    pjCustomResourceEnterpriseNumber35 = 205521476,
    pjCustomResourceEnterpriseNumber36 = 205521477,
    pjCustomResourceEnterpriseNumber37 = 205521478,
    pjCustomResourceEnterpriseNumber38 = 205521479,
    pjCustomResourceEnterpriseNumber39 = 205521480,
    pjCustomResourceEnterpriseNumber40 = 205521481,
    pjCustomResourceEnterpriseText1 = 205521542,
    pjCustomResourceEnterpriseText2 = 205521543,
    pjCustomResourceEnterpriseText3 = 205521544,
    pjCustomResourceEnterpriseText4 = 205521545,
    pjCustomResourceEnterpriseText5 = 205521546,
    pjCustomResourceEnterpriseText6 = 205521547,
    pjCustomResourceEnterpriseText7 = 205521548,
    pjCustomResourceEnterpriseText8 = 205521549,
    pjCustomResourceEnterpriseText9 = 205521550,
    pjCustomResourceEnterpriseText10 = 205521551,
    pjCustomResourceEnterpriseText11 = 205521552,
    pjCustomResourceEnterpriseText12 = 205521553,
    pjCustomResourceEnterpriseText13 = 205521554,
    pjCustomResourceEnterpriseText14 = 205521555,
    pjCustomResourceEnterpriseText15 = 205521556,
    pjCustomResourceEnterpriseText16 = 205521557,
    pjCustomResourceEnterpriseText17 = 205521558,
    pjCustomResourceEnterpriseText18 = 205521559,
    pjCustomResourceEnterpriseText19 = 205521560,
    pjCustomResourceEnterpriseText20 = 205521561,
    pjCustomResourceEnterpriseText21 = 205521562,
    pjCustomResourceEnterpriseText22 = 205521563,
    pjCustomResourceEnterpriseText23 = 205521564,
    pjCustomResourceEnterpriseText24 = 205521565,
    pjCustomResourceEnterpriseText25 = 205521566,
    pjCustomResourceEnterpriseText26 = 205521567,
    pjCustomResourceEnterpriseText27 = 205521568,
    pjCustomResourceEnterpriseText28 = 205521569,
    pjCustomResourceEnterpriseText29 = 205521570,
    pjCustomResourceEnterpriseText30 = 205521571,
    pjCustomResourceEnterpriseText31 = 205521572,
    pjCustomResourceEnterpriseText32 = 205521573,
    pjCustomResourceEnterpriseText33 = 205521574,
    pjCustomResourceEnterpriseText34 = 205521575,
    pjCustomResourceEnterpriseText35 = 205521576,
    pjCustomResourceEnterpriseText36 = 205521577,
    pjCustomResourceEnterpriseText37 = 205521578,
    pjCustomResourceEnterpriseText38 = 205521579,
    pjCustomResourceEnterpriseText39 = 205521580,
    pjCustomResourceEnterpriseText40 = 205521581
};

enum __declspec(uuid("91f4fe36-0a56-11d3-8c21-00c04f72f323"))
PjCustomFieldAttribute
{
    pjFieldAttributeNone = 0,
    pjFieldAttributeFormula = 1,
    pjFieldAttributeValueList = 2
};

enum __declspec(uuid("2d69d27e-0a57-11d3-8c21-00c04f72f323"))
PjSummaryCalc
{
    pjCalcNone = 10,
    pjCalcFormula = 11,
    pjCalcRollupAverage = 4,
    pjCalcRollupAverageFirstSublevel = 5,
    pjCalcRollupCountAll = 2,
    pjCalcRollupCountFirstSublevel = 6,
    pjCalcRollupCountNonsummaries = 7,
    pjCalcRollupMax = 0,
    pjCalcRollupMin = 1,
    pjCalcRollupAnd = 1,
    pjCalcRollupOr = 0,
    pjCalcRollupSum = 3
};

enum __declspec(uuid("44cabd10-0a5d-11d3-8c21-00c04f72f323"))
PjCriteriaList
{
    pjCriteriaNonSummary = 0,
    pjCriteriaSummary = 1,
    pjCriteriaProjectSummary = 2
};

enum __declspec(uuid("49a565fa-0a5e-11d3-8c21-00c04f72f323"))
PjIndicator
{
    pjIndicatorNone = 0,
    pjIndicatorSphereLime = 1,
    pjIndicatorSphereYellow = 2,
    pjIndicatorSphereRed = 3,
    pjIndicatorSphereBlack = 4,
    pjIndicatorSphereWhite = 5,
    pjIndicatorSphereAqua = 6,
    pjIndicatorSphereGreen = 7,
    pjIndicatorSphereBlue = 8,
    pjIndicatorSphereFuschia = 9,
    pjIndicatorSpherePurple = 10,
    pjIndicatorSphereMaroon = 11,
    pjIndicatorSphereGray = 12,
    pjIndicatorSphereSilver = 13,
    pjIndicatorFlagLime = 14,
    pjIndicatorFlagYellow = 15,
    pjIndicatorFlagRed = 16,
    pjIndicatorFlagWhite = 17,
    pjIndicatorFlagAqua = 18,
    pjIndicatorFlagBlue = 19,
    pjIndicatorFlagFuschia = 20,
    pjIndicatorFlagSilver = 21,
    pjIndicatorSquareLime = 22,
    pjIndicatorSquareYellow = 23,
    pjIndicatorSquareRed = 24,
    pjIndicatorSquareBlack = 25,
    pjIndicatorSquareWhite = 26,
    pjIndicatorPlusLime = 27,
    pjIndicatorPlusYellow = 28,
    pjIndicatorPlusRed = 29,
    pjIndicatorPlusBlack = 30,
    pjIndicatorPlusWhite = 31,
    pjIndicatorMinusLime = 32,
    pjIndicatorMinusYellow = 33,
    pjIndicatorMinusRed = 34,
    pjIndicatorMinusBlack = 35,
    pjIndicatorMinusWhite = 36,
    pjIndicatorDiamondLime = 37,
    pjIndicatorDiamondYellow = 38,
    pjIndicatorDiamondRed = 39,
    pjIndicatorArrowLeft = 40,
    pjIndicatorArrowRight = 41,
    pjIndicatorArrowDouble = 42,
    pjIndicatorArrowUp = 43,
    pjIndicatorArrowDown = 44,
    pjIndicatorCircleSolidFill = 45,
    pjIndicatorCircleBottomFill = 46,
    pjIndicatorCircleLeftFill = 47,
    pjIndicatorCircleTopFill = 48,
    pjIndicatorCircleRightFill = 49,
    pjIndicatorCircleRoundFill = 50,
    pjIndicatorCircleHollow = 51,
    pjIndicatorLightBulbOff = 52,
    pjIndicatorLightBulbOn = 53,
    pjIndicatorCheckMark = 54,
    pjIndicatorDeleteMark = 55,
    pjIndicatorQuestionMark = 56,
    pjIndicatorClock = 57,
    pjIndicatorPushPin = 58,
    pjIndicatorFaceHappyYellow = 59,
    pjIndicatorFaceHappyLime = 60,
    pjIndicatorFaceStraightYellow = 61,
    pjIndicatorFaceStraightAqua = 62,
    pjIndicatorFaceSadYellow = 63,
    pjIndicatorFaceSadRed = 64,
    pjIndicatorDashGray = 65
};

enum __declspec(uuid("32faca06-0a5f-11d3-8c21-00c04f72f323"))
PjComparison
{
    pjCompareAnyValue = 11,
    pjCompareEquals = 5,
    pjCompareNotEqual = 6,
    pjCompareGreaterThan = 1,
    pjCompareGreaterThanOrEqual = 3,
    pjCompareLessThan = 2,
    pjCompareLessThanOrEqual = 4,
    pjCompareWithin = 0,
    pjCompareNotWithin = 8,
    pjCompareContains = 7,
    pjCompareNotContains = 9,
    pjCompareContainsExactly = 10
};

enum __declspec(uuid("6d98f728-0a64-11d3-8c21-00c04f72f323"))
PjListOrder
{
    pjListOrderDefault = 0,
    pjListOrderAscending = 1,
    pjListOrderDescending = 2
};

enum __declspec(uuid("247ec60e-0c07-11d3-8c21-00c04f72f323"))
PjValueListItem
{
    pjValueListValue = 0,
    pjValueListDescription = 1,
    pjValueListPhonetics = 2
};

enum __declspec(uuid("708bf2e0-9222-11cf-982c-00aa00322803"))
PjFileFormat
{
    pjMPP = 0,
    pjTXT = 3,
    pjCSV = 4,
    pjXLS = 5,
    pjMPT = 11,
    pjXLSX = 20,
    pjXLSB = 21,
    pjMPP9 = 22,
    pjMPP12 = 23
};

enum __declspec(uuid("24e3b6d0-9223-11cf-982c-00aa00322803"))
PjFillPattern
{
    pjHollowPattern = 0,
    pjSolidFillPattern = 1,
    pjLightFillPattern = 2,
    pjMediumFillPattern = 3,
    pjDarkFillPattern = 4,
    pjDiagonalLeftPattern = 5,
    pjDiagonalRightPattern = 6,
    pjDiagonalCrossPattern = 7,
    pjLineVerticalPattern = 8,
    pjLineHorizontalPattern = 9,
    pjLineCrossPattern = 10
};

enum __declspec(uuid("7da634f0-9223-11cf-982c-00aa00322803"))
PjFormatUnit
{
    pjMinutes = 3,
    pjHours = 5,
    pjDays = 7,
    pjWeeks = 9,
    pjMonths = 11,
    pjElapsedMinutes = 4,
    pjElapsedHours = 6,
    pjElapsedDays = 8,
    pjElapsedWeeks = 10,
    pjElapsedMonths = 12,
    pjMinutesEstimated = 35,
    pjHoursEstimated = 37,
    pjDaysEstimated = 39,
    pjWeeksEstimated = 41,
    pjMonthsEstimated = 43,
    pjElapsedMinutesEstimated = 36,
    pjElapsedHoursEstimated = 38,
    pjElapsedDaysEstimated = 40,
    pjElapsedWeeksEstimated = 42,
    pjElapsedMonthsEstimated = 44
};

enum __declspec(uuid("c9228510-9225-11cf-982c-00aa00322803"))
PjGanttBarLink
{
    pjNoGanttBarLinks = 0,
    pjToTop = 1,
    pjToEnd = 2
};

enum __declspec(uuid("f96fb650-9225-11cf-982c-00aa00322803"))
PjLegend
{
    pjNoLegend = 0,
    pjAfterLastPage = 1,
    pjOnEveryPage = 2
};

enum __declspec(uuid("be968a40-9226-11cf-982c-00aa00322803"))
PjLevelOrder
{
    pjLevelID = 0,
    pjLevelStandard = 1,
    pjLevelPriority = 2
};

enum __declspec(uuid("a4cbd720-a17f-11d0-b4f9-00a0c9044f3a"))
PjCostRateTable
{
    pjCostRateTableA = 0,
    pjCostRateTableB = 1,
    pjCostRateTableC = 2,
    pjCostRateTableD = 3,
    pjCostRateTableE = 4
};

enum __declspec(uuid("7b7597d1-0c9f-11d0-8c43-00a0c904dcd4"))
PjLevelPeriodBasis
{
    pjMinuteByMinute = 0,
    pjHourByHour = 1,
    pjDayByDay = 2,
    pjWeekByWeek = 3,
    pjMonthByMonth = 4
};

enum __declspec(uuid("f9f1bac0-9226-11cf-982c-00aa00322803"))
PjMailField
{
    pjMailTaskContact = 188743792,
    pjMailTaskCost = 188743685,
    pjMailTaskCost1 = 188743786,
    pjMailTaskCost10 = 188743944,
    pjMailTaskCost2 = 188743787,
    pjMailTaskCost3 = 188743788,
    pjMailTaskCost4 = 188743938,
    pjMailTaskCost5 = 188743939,
    pjMailTaskCost6 = 188743940,
    pjMailTaskCost7 = 188743941,
    pjMailTaskCost8 = 188743942,
    pjMailTaskCost9 = 188743943,
    pjMailTaskCritical = 188743699,
    pjMailTaskDate1 = 188743945,
    pjMailTaskDate10 = 188743954,
    pjMailTaskDate2 = 188743946,
    pjMailTaskDate3 = 188743947,
    pjMailTaskDate4 = 188743948,
    pjMailTaskDate5 = 188743949,
    pjMailTaskDate6 = 188743950,
    pjMailTaskDate7 = 188743951,
    pjMailTaskDate8 = 188743952,
    pjMailTaskDate9 = 188743953,
    pjMailTaskDuration = 188743709,
    pjMailTaskDuration1 = 188743783,
    pjMailTaskDuration10 = 188743961,
    pjMailTaskDuration2 = 188743784,
    pjMailTaskDuration3 = 188743785,
    pjMailTaskDuration4 = 188743955,
    pjMailTaskDuration5 = 188743956,
    pjMailTaskDuration6 = 188743957,
    pjMailTaskDuration7 = 188743958,
    pjMailTaskDuration8 = 188743959,
    pjMailTaskDuration9 = 188743960,
    pjMailTaskEarlyFinish = 188743718,
    pjMailTaskEarlyStart = 188743717,
    pjMailTaskFinish1 = 188743733,
    pjMailTaskFinish10 = 188743971,
    pjMailTaskFinish2 = 188743736,
    pjMailTaskFinish3 = 188743739,
    pjMailTaskFinish4 = 188743742,
    pjMailTaskFinish5 = 188743745,
    pjMailTaskFinish6 = 188743963,
    pjMailTaskFinish7 = 188743965,
    pjMailTaskFinish8 = 188743967,
    pjMailTaskFinish9 = 188743969,
    pjMailTaskFixedCost = 188743688,
    pjMailTaskFlag1 = 188743752,
    pjMailTaskFlag10 = 188743761,
    pjMailTaskFlag11 = 188743972,
    pjMailTaskFlag12 = 188743973,
    pjMailTaskFlag13 = 188743974,
    pjMailTaskFlag14 = 188743975,
    pjMailTaskFlag15 = 188743976,
    pjMailTaskFlag16 = 188743977,
    pjMailTaskFlag17 = 188743978,
    pjMailTaskFlag18 = 188743979,
    pjMailTaskFlag19 = 188743980,
    pjMailTaskFlag2 = 188743753,
    pjMailTaskFlag20 = 188743981,
    pjMailTaskFlag3 = 188743754,
    pjMailTaskFlag4 = 188743755,
    pjMailTaskFlag5 = 188743756,
    pjMailTaskFlag6 = 188743757,
    pjMailTaskFlag7 = 188743758,
    pjMailTaskFlag8 = 188743759,
    pjMailTaskFlag9 = 188743760,
    pjMailTaskFreeSlack = 188743701,
    pjMailTaskLateFinish = 188743720,
    pjMailTaskLateStart = 188743719,
    pjMailTaskMarked = 188743751,
    pjMailTaskName = 188743694,
    pjMailTaskNumber1 = 188743767,
    pjMailTaskNumber10 = 188743986,
    pjMailTaskNumber11 = 188743987,
    pjMailTaskNumber12 = 188743988,
    pjMailTaskNumber13 = 188743989,
    pjMailTaskNumber14 = 188743990,
    pjMailTaskNumber15 = 188743991,
    pjMailTaskNumber16 = 188743992,
    pjMailTaskNumber17 = 188743993,
    pjMailTaskNumber18 = 188743994,
    pjMailTaskNumber19 = 188743995,
    pjMailTaskNumber2 = 188743768,
    pjMailTaskNumber20 = 188743996,
    pjMailTaskNumber3 = 188743769,
    pjMailTaskNumber4 = 188743770,
    pjMailTaskNumber5 = 188743771,
    pjMailTaskNumber6 = 188743982,
    pjMailTaskNumber7 = 188743983,
    pjMailTaskNumber8 = 188743984,
    pjMailTaskNumber9 = 188743985,
    pjMailTaskPercentComplete = 188743712,
    pjMailTaskPercentWorkComplete = 188743713,
    pjMailTaskPriority = 188743705,
    pjMailTaskProject = 188743764,
    pjMailTaskResourceNames = 188743729,
    pjMailTaskStart1 = 188743732,
    pjMailTaskStart10 = 188743970,
    pjMailTaskStart2 = 188743735,
    pjMailTaskStart3 = 188743738,
    pjMailTaskStart4 = 188743741,
    pjMailTaskStart5 = 188743744,
    pjMailTaskStart6 = 188743962,
    pjMailTaskStart7 = 188743964,
    pjMailTaskStart8 = 188743966,
    pjMailTaskStart9 = 188743968,
    pjMailTaskText1 = 188743731,
    pjMailTaskText10 = 188743750,
    pjMailTaskText11 = 188743997,
    pjMailTaskText12 = 188743998,
    pjMailTaskText13 = 188743999,
    pjMailTaskText14 = 188744000,
    pjMailTaskText15 = 188744001,
    pjMailTaskText16 = 188744002,
    pjMailTaskText17 = 188744003,
    pjMailTaskText18 = 188744004,
    pjMailTaskText19 = 188744005,
    pjMailTaskText2 = 188743734,
    pjMailTaskText20 = 188744006,
    pjMailTaskText21 = 188744007,
    pjMailTaskText22 = 188744008,
    pjMailTaskText23 = 188744009,
    pjMailTaskText24 = 188744010,
    pjMailTaskText25 = 188744011,
    pjMailTaskText26 = 188744012,
    pjMailTaskText27 = 188744013,
    pjMailTaskText28 = 188744014,
    pjMailTaskText29 = 188744015,
    pjMailTaskText3 = 188743737,
    pjMailTaskText30 = 188744016,
    pjMailTaskText4 = 188743740,
    pjMailTaskText5 = 188743743,
    pjMailTaskText6 = 188743746,
    pjMailTaskText7 = 188743747,
    pjMailTaskText8 = 188743748,
    pjMailTaskText9 = 188743749,
    pjMailTaskTotalSlack = 188743702,
    pjMailTaskWBS = 188743696,
    pjMailActualWork = 32773,
    pjMailWork = 32772,
    pjMailComments = 32769,
    pjMailStart = 32770,
    pjMailFinish = 32771
};

enum __declspec(uuid("e57b9d80-9227-11cf-982c-00aa00322803"))
PjMailSystem
{
    pjNoMailSystem = 0,
    pjMAPI = 1,
    pjMAPICompatible = 2
};

enum __declspec(uuid("3453f930-9228-11cf-982c-00aa00322803"))
PjMergeType
{
    pjDoNotMerge = 0,
    pjMerge = 1,
    pjPrompt = 2,
    pjAppend = 3
};

enum __declspec(uuid("66116ea0-9228-11cf-982c-00aa00322803"))
PjMessageType
{
    pjOKOnly = 0,
    pjOKCancel = 1,
    pjYesNo = 2,
    pjYesNoCancel = 3
};

enum __declspec(uuid("2c69e010-9229-11cf-982c-00aa00322803"))
PjMonthLabel
{
    pjMonthLabelMonth_mm = 57,
    pjMonthLabelMonth_mm_yy = 86,
    pjMonthLabelMonth_mm_yyy = 85,
    pjMonthLabelMonth_m = 11,
    pjMonthLabelMonth_mmm = 10,
    pjMonthLabelMonth_mmm_yyy = 8,
    pjMonthLabelMonth_mmmm = 9,
    pjMonthLabelMonth_mmmm_yyyy = 7,
    pjMonthLabelMonthFromEnd_mm = 59,
    pjMonthLabelMonthFromEnd_Mmm = 58,
    pjMonthLabelMonthFromEnd_Month_mm = 45,
    pjMonthLabelMonthFromStart_mm = 61,
    pjMonthLabelMonthFromStart_Mmm = 60,
    pjMonthLabelMonthFromStart_Month_mm = 44,
    pjMonthLabelNoDateFormat = 35
};

enum __declspec(uuid("9ac1e430-9229-11cf-982c-00aa00322803"))
PjNonWorkingPlacement
{
    pjBehind = 0,
    pjInFront = 1,
    pjDoNotDraw = 2
};

enum __declspec(uuid("4ac50900-1348-11d0-98e1-00aa0051e224"))
PjYesNoAutomatic
{
    pjNo = 0,
    pjYes = 1,
    pjAuto = 2
};

enum __declspec(uuid("d2ae6fe0-9229-11cf-982c-00aa00322803"))
PjOrganizer
{
    pjViews = 0,
    pjTables = 1,
    pjFilters = 2,
    pjModules = 3,
    pjReports = 4,
    pjCalendars = 5,
    pjToolbars = 6,
    pjMaps = 7,
    pjForms = 8,
    pjFields = 9,
    pjGroups = 10,
    pjDrawings = 11
};

enum __declspec(uuid("2a8d3f10-922a-11cf-982c-00aa00322803"))
PjPageSetupCalendarItem
{
    pjAllCalendarItems = 0,
    pjMonthlyTitles = 1,
    pjPreviousNextMonths = 2,
    pjAdditionalTasks = 3
};

enum __declspec(uuid("9b54b7b0-922a-11cf-982c-00aa00322803"))
PjPERTField
{
    pjPERTTaskWork = 188743680,
    pjPERTTaskBaselineWork = 188743681,
    pjPERTTaskActualWork = 188743682,
    pjPERTTaskWorkVariance = 188743683,
    pjPERTTaskRemainingWork = 188743684,
    pjPERTTaskCost = 188743685,
    pjPERTTaskBaselineCost = 188743686,
    pjPERTTaskActualCost = 188743687,
    pjPERTTaskFixedCost = 188743688,
    pjPERTTaskCostVariance = 188743689,
    pjPERTTaskRemainingCost = 188743690,
    pjPERTTaskBCWP = 188743691,
    pjPERTTaskBCWS = 188743692,
    pjPERTTaskSV = 188743693,
    pjPERTTaskName = 188743694,
    pjPERTTaskWBS = 188743696,
    pjPERTTaskConstraintType = 188743697,
    pjPERTTaskConstraintDate = 188743698,
    pjPERTTaskCritical = 188743699,
    pjPERTTaskLevelingDelay = 188743700,
    pjPERTTaskFreeSlack = 188743701,
    pjPERTTaskTotalSlack = 188743702,
    pjPERTTaskID = 188743703,
    pjPERTTaskMilestone = 188743704,
    pjPERTTaskPriority = 188743705,
    pjPERTTaskSubproject = 188743706,
    pjPERTTaskBaselineDuration = 188743707,
    pjPERTTaskActualDuration = 188743708,
    pjPERTTaskDuration = 188743709,
    pjPERTTaskDurationVariance = 188743710,
    pjPERTTaskRemainingDuration = 188743711,
    pjPERTTaskPercentComplete = 188743712,
    pjPERTTaskPercentWorkComplete = 188743713,
    pjPERTTaskStart = 188743715,
    pjPERTTaskFinish = 188743716,
    pjPERTTaskEarlyStart = 188743717,
    pjPERTTaskEarlyFinish = 188743718,
    pjPERTTaskLateStart = 188743719,
    pjPERTTaskLateFinish = 188743720,
    pjPERTTaskActualStart = 188743721,
    pjPERTTaskActualFinish = 188743722,
    pjPERTTaskBaselineStart = 188743723,
    pjPERTTaskBaselineFinish = 188743724,
    pjPERTTaskStartVariance = 188743725,
    pjPERTTaskFinishVariance = 188743726,
    pjPERTTaskPredecessors = 188743727,
    pjPERTTaskSuccessors = 188743728,
    pjPERTTaskResourceNames = 188743729,
    pjPERTTaskResourceInitials = 188743730,
    pjPERTTaskText1 = 188743731,
    pjPERTTaskStart1 = 188743732,
    pjPERTTaskFinish1 = 188743733,
    pjPERTTaskText2 = 188743734,
    pjPERTTaskStart2 = 188743735,
    pjPERTTaskFinish2 = 188743736,
    pjPERTTaskText3 = 188743737,
    pjPERTTaskStart3 = 188743738,
    pjPERTTaskFinish3 = 188743739,
    pjPERTTaskText4 = 188743740,
    pjPERTTaskStart4 = 188743741,
    pjPERTTaskFinish4 = 188743742,
    pjPERTTaskText5 = 188743743,
    pjPERTTaskStart5 = 188743744,
    pjPERTTaskFinish5 = 188743745,
    pjPERTTaskText6 = 188743746,
    pjPERTTaskText7 = 188743747,
    pjPERTTaskText8 = 188743748,
    pjPERTTaskText9 = 188743749,
    pjPERTTaskText10 = 188743750,
    pjPERTTaskMarked = 188743751,
    pjPERTTaskFlag1 = 188743752,
    pjPERTTaskFlag2 = 188743753,
    pjPERTTaskFlag3 = 188743754,
    pjPERTTaskFlag4 = 188743755,
    pjPERTTaskFlag5 = 188743756,
    pjPERTTaskFlag6 = 188743757,
    pjPERTTaskFlag7 = 188743758,
    pjPERTTaskFlag8 = 188743759,
    pjPERTTaskFlag9 = 188743760,
    pjPERTTaskFlag10 = 188743761,
    pjPERTTaskRollup = 188743762,
    pjPERTTaskCV = 188743763,
    pjPERTTaskProject = 188743764,
    pjPERTTaskOutlineLevel = 188743765,
    pjPERTTaskUniqueID = 188743766,
    pjPERTTaskNumber1 = 188743767,
    pjPERTTaskNumber2 = 188743768,
    pjPERTTaskNumber3 = 188743769,
    pjPERTTaskNumber4 = 188743770,
    pjPERTTaskNumber5 = 188743771,
    pjPERTTaskSummary = 188743772,
    pjPERTTaskCreated = 188743773,
    pjPERTTaskSheetNotes = 188743774,
    pjPERTTaskUniquePredecessors = 188743775,
    pjPERTTaskUniqueSuccessors = 188743776,
    pjPERTTaskObjects = 188743777,
    pjPERTTaskLinkedFields = 188743778,
    pjPERTTaskResume = 188743779,
    pjPERTTaskStop = 188743780,
    pjPERTTaskOutlineNumber = 188743782,
    pjPERTTaskDuration1 = 188743783,
    pjPERTTaskDuration2 = 188743784,
    pjPERTTaskDuration3 = 188743785,
    pjPERTTaskCost1 = 188743786,
    pjPERTTaskCost2 = 188743787,
    pjPERTTaskCost3 = 188743788,
    pjPERTTaskHideBar = 188743789,
    pjPERTTaskConfirmed = 188743790,
    pjPERTTaskUpdateNeeded = 188743791,
    pjPERTTaskContact = 188743792,
    pjPERTTaskResourceGroup = 188743793,
    pjPERTTaskACWP = 188743800,
    pjPERTTaskType = 188743808,
    pjPERTTaskRecurring = 188743809,
    pjPERTTaskEffortDriven = 188743812,
    pjPERTTaskOvertimeWork = 188743843,
    pjPERTTaskActualOvertimeWork = 188743844,
    pjPERTTaskRemainingOvertimeWork = 188743845,
    pjPERTTaskRegularWork = 188743846,
    pjPERTTaskOvertimeCost = 188743848,
    pjPERTTaskActualOvertimeCost = 188743849,
    pjPERTTaskRemainingOvertimeCost = 188743850,
    pjPERTTaskFixedCostAccrual = 188743880,
    pjPERTTaskHyperlink = 188743897,
    pjPERTTaskHyperlinkAddress = 188743898,
    pjPERTTaskHyperlinkSubAddress = 188743899,
    pjPERTTaskHyperlinkHref = 188743900,
    pjPERTTaskIsAssn = 188743904,
    pjPERTTaskOverallocated = 188743905,
    pjPERTTaskExternalTask = 188743912,
    pjPERTTaskSubprojectReadOnly = 188743926,
    pjPERTTaskResponsePending = 188743930,
    pjPERTTaskTeamStatusPending = 188743931,
    pjPERTTaskLevelingCanSplit = 188743932,
    pjPERTTaskLevelAssignments = 188743933,
    pjPERTTaskWorkContour = 188743936,
    pjPERTTaskCost4 = 188743938,
    pjPERTTaskCost5 = 188743939,
    pjPERTTaskCost6 = 188743940,
    pjPERTTaskCost7 = 188743941,
    pjPERTTaskCost8 = 188743942,
    pjPERTTaskCost9 = 188743943,
    pjPERTTaskCost10 = 188743944,
    pjPERTTaskDate1 = 188743945,
    pjPERTTaskDate2 = 188743946,
    pjPERTTaskDate3 = 188743947,
    pjPERTTaskDate4 = 188743948,
    pjPERTTaskDate5 = 188743949,
    pjPERTTaskDate6 = 188743950,
    pjPERTTaskDate7 = 188743951,
    pjPERTTaskDate8 = 188743952,
    pjPERTTaskDate9 = 188743953,
    pjPERTTaskDate10 = 188743954,
    pjPERTTaskDuration4 = 188743955,
    pjPERTTaskDuration5 = 188743956,
    pjPERTTaskDuration6 = 188743957,
    pjPERTTaskDuration7 = 188743958,
    pjPERTTaskDuration8 = 188743959,
    pjPERTTaskDuration9 = 188743960,
    pjPERTTaskDuration10 = 188743961,
    pjPERTTaskStart6 = 188743962,
    pjPERTTaskFinish6 = 188743963,
    pjPERTTaskStart7 = 188743964,
    pjPERTTaskFinish7 = 188743965,
    pjPERTTaskStart8 = 188743966,
    pjPERTTaskFinish8 = 188743967,
    pjPERTTaskStart9 = 188743968,
    pjPERTTaskFinish9 = 188743969,
    pjPERTTaskStart10 = 188743970,
    pjPERTTaskFinish10 = 188743971,
    pjPERTTaskFlag11 = 188743972,
    pjPERTTaskFlag12 = 188743973,
    pjPERTTaskFlag13 = 188743974,
    pjPERTTaskFlag14 = 188743975,
    pjPERTTaskFlag15 = 188743976,
    pjPERTTaskFlag16 = 188743977,
    pjPERTTaskFlag17 = 188743978,
    pjPERTTaskFlag18 = 188743979,
    pjPERTTaskFlag19 = 188743980,
    pjPERTTaskFlag20 = 188743981,
    pjPERTTaskNumber6 = 188743982,
    pjPERTTaskNumber7 = 188743983,
    pjPERTTaskNumber8 = 188743984,
    pjPERTTaskNumber9 = 188743985,
    pjPERTTaskNumber10 = 188743986,
    pjPERTTaskNumber11 = 188743987,
    pjPERTTaskNumber12 = 188743988,
    pjPERTTaskNumber13 = 188743989,
    pjPERTTaskNumber14 = 188743990,
    pjPERTTaskNumber15 = 188743991,
    pjPERTTaskNumber16 = 188743992,
    pjPERTTaskNumber17 = 188743993,
    pjPERTTaskNumber18 = 188743994,
    pjPERTTaskNumber19 = 188743995,
    pjPERTTaskNumber20 = 188743996,
    pjPERTTaskText11 = 188743997,
    pjPERTTaskText12 = 188743998,
    pjPERTTaskText13 = 188743999,
    pjPERTTaskText14 = 188744000,
    pjPERTTaskText15 = 188744001,
    pjPERTTaskText16 = 188744002,
    pjPERTTaskText17 = 188744003,
    pjPERTTaskText18 = 188744004,
    pjPERTTaskText19 = 188744005,
    pjPERTTaskText20 = 188744006,
    pjPERTTaskText21 = 188744007,
    pjPERTTaskText22 = 188744008,
    pjPERTTaskText23 = 188744009,
    pjPERTTaskText24 = 188744010,
    pjPERTTaskText25 = 188744011,
    pjPERTTaskText26 = 188744012,
    pjPERTTaskText27 = 188744013,
    pjPERTTaskText28 = 188744014,
    pjPERTTaskText29 = 188744015,
    pjPERTTaskText30 = 188744016,
    pjPERTTaskResourcePhonetics = 188744029,
    pjPERTTaskAssignmentDelay = 188744046,
    pjPERTTaskAssignmentUnits = 188744047,
    pjPERTTaskCostRateTable = 188744048,
    pjPERTTaskPreLeveledStart = 188744049,
    pjPERTTaskPreLeveledFinish = 188744050,
    pjPERTTaskEstimated = 188744076,
    pjPERTTaskIgnoreResourceCalendar = 188744079,
    pjPERTTaskCalendar = 188744082,
    pjPERTTaskOutlineCode1 = 188744096,
    pjPERTTaskOutlineCode2 = 188744098,
    pjPERTTaskOutlineCode3 = 188744100,
    pjPERTTaskOutlineCode4 = 188744102,
    pjPERTTaskOutlineCode5 = 188744104,
    pjPERTTaskOutlineCode6 = 188744106,
    pjPERTTaskOutlineCode7 = 188744108,
    pjPERTTaskOutlineCode8 = 188744110,
    pjPERTTaskOutlineCode9 = 188744112,
    pjPERTTaskOutlineCode10 = 188744114,
    pjPERTTaskDeadline = 188744117,
    pjPERTTaskStartSlack = 188744118,
    pjPERTTaskFinishSlack = 188744119,
    pjPERTTaskVAC = 188744121,
    pjPERTTaskGroupBySummary = 188744126,
    pjPERTTaskWBSPredecessors = 188744129,
    pjPERTTaskWBSSuccessors = 188744130,
    pjPERTTaskResourceType = 188744131,
    pjPERTTaskBaselineFixedCost = 188744160,
    pjPERTTaskBaseline1Start = 188744162,
    pjPERTTaskBaseline1Finish = 188744163,
    pjPERTTaskBaseline1Cost = 188744164,
    pjPERTTaskBaseline1Work = 188744165,
    pjPERTTaskBaseline1Duration = 188744167,
    pjPERTTaskBaseline1FixedCost = 188744169,
    pjPERTTaskBaseline2Start = 188744173,
    pjPERTTaskBaseline2Finish = 188744174,
    pjPERTTaskBaseline2Cost = 188744175,
    pjPERTTaskBaseline2Work = 188744176,
    pjPERTTaskBaseline2Duration = 188744178,
    pjPERTTaskBaseline2FixedCost = 188744180,
    pjPERTTaskBaseline3Start = 188744184,
    pjPERTTaskBaseline3Finish = 188744185,
    pjPERTTaskBaseline3Cost = 188744186,
    pjPERTTaskBaseline3Work = 188744187,
    pjPERTTaskBaseline3Duration = 188744189,
    pjPERTTaskBaseline3FixedCost = 188744191,
    pjPERTTaskBaseline4Start = 188744195,
    pjPERTTaskBaseline4Finish = 188744196,
    pjPERTTaskBaseline4Cost = 188744197,
    pjPERTTaskBaseline4Work = 188744198,
    pjPERTTaskBaseline4Duration = 188744200,
    pjPERTTaskBaseline4FixedCost = 188744202,
    pjPERTTaskBaseline5Start = 188744206,
    pjPERTTaskBaseline5Finish = 188744207,
    pjPERTTaskBaseline5Cost = 188744208,
    pjPERTTaskBaseline5Work = 188744209,
    pjPERTTaskBaseline5Duration = 188744211,
    pjPERTTaskBaseline5FixedCost = 188744213,
    pjPERTTaskCPI = 188744217,
    pjPERTTaskSPI = 188744218,
    pjPERTTaskCVPercent = 188744219,
    pjPERTTaskSVPercent = 188744220,
    pjPERTTaskEAC = 188744221,
    pjPERTTaskTCPI = 188744222,
    pjPERTTaskStatus = 188744223,
    pjPERTTaskBaseline6Start = 188744224,
    pjPERTTaskBaseline6Finish = 188744225,
    pjPERTTaskBaseline6Cost = 188744226,
    pjPERTTaskBaseline6Work = 188744227,
    pjPERTTaskBaseline6Duration = 188744229,
    pjPERTTaskBaseline6FixedCost = 188744231,
    pjPERTTaskBaseline7Start = 188744235,
    pjPERTTaskBaseline7Finish = 188744236,
    pjPERTTaskBaseline7Cost = 188744237,
    pjPERTTaskBaseline7Work = 188744238,
    pjPERTTaskBaseline7Duration = 188744240,
    pjPERTTaskBaseline7FixedCost = 188744242,
    pjPERTTaskBaseline8Start = 188744246,
    pjPERTTaskBaseline8Finish = 188744247,
    pjPERTTaskBaseline8Cost = 188744248,
    pjPERTTaskBaseline8Work = 188744249,
    pjPERTTaskBaseline8Duration = 188744251,
    pjPERTTaskBaseline8FixedCost = 188744253,
    pjPERTTaskBaseline9Start = 188744257,
    pjPERTTaskBaseline9Finish = 188744258,
    pjPERTTaskBaseline9Cost = 188744259,
    pjPERTTaskBaseline9Work = 188744260,
    pjPERTTaskBaseline9Duration = 188744262,
    pjPERTTaskBaseline9FixedCost = 188744264,
    pjPERTTaskBaseline10Start = 188744268,
    pjPERTTaskBaseline10Finish = 188744269,
    pjPERTTaskBaseline10Cost = 188744270,
    pjPERTTaskBaseline10Work = 188744271,
    pjPERTTaskBaseline10Duration = 188744273,
    pjPERTTaskBaseline10FixedCost = 188744275,
    pjPERTTaskEnterpriseCost1 = 188744279,
    pjPERTTaskEnterpriseCost2 = 188744280,
    pjPERTTaskEnterpriseCost3 = 188744281,
    pjPERTTaskEnterpriseCost4 = 188744282,
    pjPERTTaskEnterpriseCost5 = 188744283,
    pjPERTTaskEnterpriseCost6 = 188744284,
    pjPERTTaskEnterpriseCost7 = 188744285,
    pjPERTTaskEnterpriseCost8 = 188744286,
    pjPERTTaskEnterpriseCost9 = 188744287,
    pjPERTTaskEnterpriseCost10 = 188744288,
    pjPERTTaskEnterpriseDate1 = 188744289,
    pjPERTTaskEnterpriseDate2 = 188744290,
    pjPERTTaskEnterpriseDate3 = 188744291,
    pjPERTTaskEnterpriseDate4 = 188744292,
    pjPERTTaskEnterpriseDate5 = 188744293,
    pjPERTTaskEnterpriseDate6 = 188744294,
    pjPERTTaskEnterpriseDate7 = 188744295,
    pjPERTTaskEnterpriseDate8 = 188744296,
    pjPERTTaskEnterpriseDate9 = 188744297,
    pjPERTTaskEnterpriseDate10 = 188744298,
    pjPERTTaskEnterpriseDate11 = 188744299,
    pjPERTTaskEnterpriseDate12 = 188744300,
    pjPERTTaskEnterpriseDate13 = 188744301,
    pjPERTTaskEnterpriseDate14 = 188744302,
    pjPERTTaskEnterpriseDate15 = 188744303,
    pjPERTTaskEnterpriseDate16 = 188744304,
    pjPERTTaskEnterpriseDate17 = 188744305,
    pjPERTTaskEnterpriseDate18 = 188744306,
    pjPERTTaskEnterpriseDate19 = 188744307,
    pjPERTTaskEnterpriseDate20 = 188744308,
    pjPERTTaskEnterpriseDate21 = 188744309,
    pjPERTTaskEnterpriseDate22 = 188744310,
    pjPERTTaskEnterpriseDate23 = 188744311,
    pjPERTTaskEnterpriseDate24 = 188744312,
    pjPERTTaskEnterpriseDate25 = 188744313,
    pjPERTTaskEnterpriseDate26 = 188744314,
    pjPERTTaskEnterpriseDate27 = 188744315,
    pjPERTTaskEnterpriseDate28 = 188744316,
    pjPERTTaskEnterpriseDate29 = 188744317,
    pjPERTTaskEnterpriseDate30 = 188744318,
    pjPERTTaskEnterpriseDuration1 = 188744319,
    pjPERTTaskEnterpriseDuration2 = 188744320,
    pjPERTTaskEnterpriseDuration3 = 188744321,
    pjPERTTaskEnterpriseDuration4 = 188744322,
    pjPERTTaskEnterpriseDuration5 = 188744323,
    pjPERTTaskEnterpriseDuration6 = 188744324,
    pjPERTTaskEnterpriseDuration7 = 188744325,
    pjPERTTaskEnterpriseDuration8 = 188744326,
    pjPERTTaskEnterpriseDuration9 = 188744327,
    pjPERTTaskEnterpriseDuration10 = 188744328,
    pjPERTTaskEnterpriseFlag1 = 188744339,
    pjPERTTaskEnterpriseFlag2 = 188744340,
    pjPERTTaskEnterpriseFlag3 = 188744341,
    pjPERTTaskEnterpriseFlag4 = 188744342,
    pjPERTTaskEnterpriseFlag5 = 188744343,
    pjPERTTaskEnterpriseFlag6 = 188744344,
    pjPERTTaskEnterpriseFlag7 = 188744345,
    pjPERTTaskEnterpriseFlag8 = 188744346,
    pjPERTTaskEnterpriseFlag9 = 188744347,
    pjPERTTaskEnterpriseFlag10 = 188744348,
    pjPERTTaskEnterpriseFlag11 = 188744349,
    pjPERTTaskEnterpriseFlag12 = 188744350,
    pjPERTTaskEnterpriseFlag13 = 188744351,
    pjPERTTaskEnterpriseFlag14 = 188744352,
    pjPERTTaskEnterpriseFlag15 = 188744353,
    pjPERTTaskEnterpriseFlag16 = 188744354,
    pjPERTTaskEnterpriseFlag17 = 188744355,
    pjPERTTaskEnterpriseFlag18 = 188744356,
    pjPERTTaskEnterpriseFlag19 = 188744357,
    pjPERTTaskEnterpriseFlag20 = 188744358,
    pjPERTTaskEnterpriseNumber1 = 188744379,
    pjPERTTaskEnterpriseNumber2 = 188744380,
    pjPERTTaskEnterpriseNumber3 = 188744381,
    pjPERTTaskEnterpriseNumber4 = 188744382,
    pjPERTTaskEnterpriseNumber5 = 188744383,
    pjPERTTaskEnterpriseNumber6 = 188744384,
    pjPERTTaskEnterpriseNumber7 = 188744385,
    pjPERTTaskEnterpriseNumber8 = 188744386,
    pjPERTTaskEnterpriseNumber9 = 188744387,
    pjPERTTaskEnterpriseNumber10 = 188744388,
    pjPERTTaskEnterpriseNumber11 = 188744389,
    pjPERTTaskEnterpriseNumber12 = 188744390,
    pjPERTTaskEnterpriseNumber13 = 188744391,
    pjPERTTaskEnterpriseNumber14 = 188744392,
    pjPERTTaskEnterpriseNumber15 = 188744393,
    pjPERTTaskEnterpriseNumber16 = 188744394,
    pjPERTTaskEnterpriseNumber17 = 188744395,
    pjPERTTaskEnterpriseNumber18 = 188744396,
    pjPERTTaskEnterpriseNumber19 = 188744397,
    pjPERTTaskEnterpriseNumber20 = 188744398,
    pjPERTTaskEnterpriseNumber21 = 188744399,
    pjPERTTaskEnterpriseNumber22 = 188744400,
    pjPERTTaskEnterpriseNumber23 = 188744401,
    pjPERTTaskEnterpriseNumber24 = 188744402,
    pjPERTTaskEnterpriseNumber25 = 188744403,
    pjPERTTaskEnterpriseNumber26 = 188744404,
    pjPERTTaskEnterpriseNumber27 = 188744405,
    pjPERTTaskEnterpriseNumber28 = 188744406,
    pjPERTTaskEnterpriseNumber29 = 188744407,
    pjPERTTaskEnterpriseNumber30 = 188744408,
    pjPERTTaskEnterpriseNumber31 = 188744409,
    pjPERTTaskEnterpriseNumber32 = 188744410,
    pjPERTTaskEnterpriseNumber33 = 188744411,
    pjPERTTaskEnterpriseNumber34 = 188744412,
    pjPERTTaskEnterpriseNumber35 = 188744413,
    pjPERTTaskEnterpriseNumber36 = 188744414,
    pjPERTTaskEnterpriseNumber37 = 188744415,
    pjPERTTaskEnterpriseNumber38 = 188744416,
    pjPERTTaskEnterpriseNumber39 = 188744417,
    pjPERTTaskEnterpriseNumber40 = 188744418,
    pjPERTTaskEnterpriseOutlineCode1 = 188744419,
    pjPERTTaskEnterpriseOutlineCode2 = 188744421,
    pjPERTTaskEnterpriseOutlineCode3 = 188744423,
    pjPERTTaskEnterpriseOutlineCode4 = 188744425,
    pjPERTTaskEnterpriseOutlineCode5 = 188744427,
    pjPERTTaskEnterpriseOutlineCode6 = 188744429,
    pjPERTTaskEnterpriseOutlineCode7 = 188744431,
    pjPERTTaskEnterpriseOutlineCode8 = 188744433,
    pjPERTTaskEnterpriseOutlineCode9 = 188744435,
    pjPERTTaskEnterpriseOutlineCode10 = 188744437,
    pjPERTTaskEnterpriseOutlineCode11 = 188744439,
    pjPERTTaskEnterpriseOutlineCode12 = 188744441,
    pjPERTTaskEnterpriseOutlineCode13 = 188744443,
    pjPERTTaskEnterpriseOutlineCode14 = 188744445,
    pjPERTTaskEnterpriseOutlineCode15 = 188744447,
    pjPERTTaskEnterpriseOutlineCode16 = 188744449,
    pjPERTTaskEnterpriseOutlineCode17 = 188744451,
    pjPERTTaskEnterpriseOutlineCode18 = 188744453,
    pjPERTTaskEnterpriseOutlineCode19 = 188744455,
    pjPERTTaskEnterpriseOutlineCode20 = 188744457,
    pjPERTTaskEnterpriseOutlineCode21 = 188744459,
    pjPERTTaskEnterpriseOutlineCode22 = 188744461,
    pjPERTTaskEnterpriseOutlineCode23 = 188744463,
    pjPERTTaskEnterpriseOutlineCode24 = 188744465,
    pjPERTTaskEnterpriseOutlineCode25 = 188744467,
    pjPERTTaskEnterpriseOutlineCode26 = 188744469,
    pjPERTTaskEnterpriseOutlineCode27 = 188744471,
    pjPERTTaskEnterpriseOutlineCode28 = 188744473,
    pjPERTTaskEnterpriseOutlineCode29 = 188744475,
    pjPERTTaskEnterpriseOutlineCode30 = 188744477,
    pjPERTTaskEnterpriseText1 = 188744479,
    pjPERTTaskEnterpriseText2 = 188744480,
    pjPERTTaskEnterpriseText3 = 188744481,
    pjPERTTaskEnterpriseText4 = 188744482,
    pjPERTTaskEnterpriseText5 = 188744483,
    pjPERTTaskEnterpriseText6 = 188744484,
    pjPERTTaskEnterpriseText7 = 188744485,
    pjPERTTaskEnterpriseText8 = 188744486,
    pjPERTTaskEnterpriseText9 = 188744487,
    pjPERTTaskEnterpriseText10 = 188744488,
    pjPERTTaskEnterpriseText11 = 188744489,
    pjPERTTaskEnterpriseText12 = 188744490,
    pjPERTTaskEnterpriseText13 = 188744491,
    pjPERTTaskEnterpriseText14 = 188744492,
    pjPERTTaskEnterpriseText15 = 188744493,
    pjPERTTaskEnterpriseText16 = 188744494,
    pjPERTTaskEnterpriseText17 = 188744495,
    pjPERTTaskEnterpriseText18 = 188744496,
    pjPERTTaskEnterpriseText19 = 188744497,
    pjPERTTaskEnterpriseText20 = 188744498,
    pjPERTTaskEnterpriseText21 = 188744499,
    pjPERTTaskEnterpriseText22 = 188744500,
    pjPERTTaskEnterpriseText23 = 188744501,
    pjPERTTaskEnterpriseText24 = 188744502,
    pjPERTTaskEnterpriseText25 = 188744503,
    pjPERTTaskEnterpriseText26 = 188744504,
    pjPERTTaskEnterpriseText27 = 188744505,
    pjPERTTaskEnterpriseText28 = 188744506,
    pjPERTTaskEnterpriseText29 = 188744507,
    pjPERTTaskEnterpriseText30 = 188744508,
    pjPERTTaskEnterpriseText31 = 188744509,
    pjPERTTaskEnterpriseText32 = 188744510,
    pjPERTTaskEnterpriseText33 = 188744511,
    pjPERTTaskEnterpriseText34 = 188744512,
    pjPERTTaskEnterpriseText35 = 188744513,
    pjPERTTaskEnterpriseText36 = 188744514,
    pjPERTTaskEnterpriseText37 = 188744515,
    pjPERTTaskEnterpriseText38 = 188744516,
    pjPERTTaskEnterpriseText39 = 188744517,
    pjPERTTaskEnterpriseText40 = 188744518,
    pjPERTTaskEnterpriseProjectCost1 = 188744529,
    pjPERTTaskEnterpriseProjectCost2 = 188744530,
    pjPERTTaskEnterpriseProjectCost3 = 188744531,
    pjPERTTaskEnterpriseProjectCost4 = 188744532,
    pjPERTTaskEnterpriseProjectCost5 = 188744533,
    pjPERTTaskEnterpriseProjectCost6 = 188744534,
    pjPERTTaskEnterpriseProjectCost7 = 188744535,
    pjPERTTaskEnterpriseProjectCost8 = 188744536,
    pjPERTTaskEnterpriseProjectCost9 = 188744537,
    pjPERTTaskEnterpriseProjectCost10 = 188744538,
    pjPERTTaskEnterpriseProjectDate1 = 188744539,
    pjPERTTaskEnterpriseProjectDate2 = 188744540,
    pjPERTTaskEnterpriseProjectDate3 = 188744541,
    pjPERTTaskEnterpriseProjectDate4 = 188744542,
    pjPERTTaskEnterpriseProjectDate5 = 188744543,
    pjPERTTaskEnterpriseProjectDate6 = 188744544,
    pjPERTTaskEnterpriseProjectDate7 = 188744545,
    pjPERTTaskEnterpriseProjectDate8 = 188744546,
    pjPERTTaskEnterpriseProjectDate9 = 188744547,
    pjPERTTaskEnterpriseProjectDate10 = 188744548,
    pjPERTTaskEnterpriseProjectDate11 = 188744549,
    pjPERTTaskEnterpriseProjectDate12 = 188744550,
    pjPERTTaskEnterpriseProjectDate13 = 188744551,
    pjPERTTaskEnterpriseProjectDate14 = 188744552,
    pjPERTTaskEnterpriseProjectDate15 = 188744553,
    pjPERTTaskEnterpriseProjectDate16 = 188744554,
    pjPERTTaskEnterpriseProjectDate17 = 188744555,
    pjPERTTaskEnterpriseProjectDate18 = 188744556,
    pjPERTTaskEnterpriseProjectDate19 = 188744557,
    pjPERTTaskEnterpriseProjectDate20 = 188744558,
    pjPERTTaskEnterpriseProjectDate21 = 188744559,
    pjPERTTaskEnterpriseProjectDate22 = 188744560,
    pjPERTTaskEnterpriseProjectDate23 = 188744561,
    pjPERTTaskEnterpriseProjectDate24 = 188744562,
    pjPERTTaskEnterpriseProjectDate25 = 188744563,
    pjPERTTaskEnterpriseProjectDate26 = 188744564,
    pjPERTTaskEnterpriseProjectDate27 = 188744565,
    pjPERTTaskEnterpriseProjectDate28 = 188744566,
    pjPERTTaskEnterpriseProjectDate29 = 188744567,
    pjPERTTaskEnterpriseProjectDate30 = 188744568,
    pjPERTTaskEnterpriseProjectDuration1 = 188744569,
    pjPERTTaskEnterpriseProjectDuration2 = 188744570,
    pjPERTTaskEnterpriseProjectDuration3 = 188744571,
    pjPERTTaskEnterpriseProjectDuration4 = 188744572,
    pjPERTTaskEnterpriseProjectDuration5 = 188744573,
    pjPERTTaskEnterpriseProjectDuration6 = 188744574,
    pjPERTTaskEnterpriseProjectDuration7 = 188744575,
    pjPERTTaskEnterpriseProjectDuration8 = 188744576,
    pjPERTTaskEnterpriseProjectDuration9 = 188744577,
    pjPERTTaskEnterpriseProjectDuration10 = 188744578,
    pjPERTTaskEnterpriseProjectOutlineCode1 = 188744589,
    pjPERTTaskEnterpriseProjectOutlineCode2 = 188744590,
    pjPERTTaskEnterpriseProjectOutlineCode3 = 188744591,
    pjPERTTaskEnterpriseProjectOutlineCode4 = 188744592,
    pjPERTTaskEnterpriseProjectOutlineCode5 = 188744593,
    pjPERTTaskEnterpriseProjectOutlineCode6 = 188744594,
    pjPERTTaskEnterpriseProjectOutlineCode7 = 188744595,
    pjPERTTaskEnterpriseProjectOutlineCode8 = 188744596,
    pjPERTTaskEnterpriseProjectOutlineCode9 = 188744597,
    pjPERTTaskEnterpriseProjectOutlineCode10 = 188744598,
    pjPERTTaskEnterpriseProjectOutlineCode11 = 188744599,
    pjPERTTaskEnterpriseProjectOutlineCode12 = 188744600,
    pjPERTTaskEnterpriseProjectOutlineCode13 = 188744601,
    pjPERTTaskEnterpriseProjectOutlineCode14 = 188744602,
    pjPERTTaskEnterpriseProjectOutlineCode15 = 188744603,
    pjPERTTaskEnterpriseProjectOutlineCode16 = 188744604,
    pjPERTTaskEnterpriseProjectOutlineCode17 = 188744605,
    pjPERTTaskEnterpriseProjectOutlineCode18 = 188744606,
    pjPERTTaskEnterpriseProjectOutlineCode19 = 188744607,
    pjPERTTaskEnterpriseProjectOutlineCode20 = 188744608,
    pjPERTTaskEnterpriseProjectOutlineCode21 = 188744609,
    pjPERTTaskEnterpriseProjectOutlineCode22 = 188744610,
    pjPERTTaskEnterpriseProjectOutlineCode23 = 188744611,
    pjPERTTaskEnterpriseProjectOutlineCode24 = 188744612,
    pjPERTTaskEnterpriseProjectOutlineCode25 = 188744613,
    pjPERTTaskEnterpriseProjectOutlineCode26 = 188744614,
    pjPERTTaskEnterpriseProjectOutlineCode27 = 188744615,
    pjPERTTaskEnterpriseProjectOutlineCode28 = 188744616,
    pjPERTTaskEnterpriseProjectOutlineCode29 = 188744617,
    pjPERTTaskEnterpriseProjectOutlineCode30 = 188744618,
    pjPERTTaskEnterpriseProjectFlag1 = 188744649,
    pjPERTTaskEnterpriseProjectFlag2 = 188744650,
    pjPERTTaskEnterpriseProjectFlag3 = 188744651,
    pjPERTTaskEnterpriseProjectFlag4 = 188744652,
    pjPERTTaskEnterpriseProjectFlag5 = 188744653,
    pjPERTTaskEnterpriseProjectFlag6 = 188744654,
    pjPERTTaskEnterpriseProjectFlag7 = 188744655,
    pjPERTTaskEnterpriseProjectFlag8 = 188744656,
    pjPERTTaskEnterpriseProjectFlag9 = 188744657,
    pjPERTTaskEnterpriseProjectFlag10 = 188744658,
    pjPERTTaskEnterpriseProjectFlag11 = 188744659,
    pjPERTTaskEnterpriseProjectFlag12 = 188744660,
    pjPERTTaskEnterpriseProjectFlag13 = 188744661,
    pjPERTTaskEnterpriseProjectFlag14 = 188744662,
    pjPERTTaskEnterpriseProjectFlag15 = 188744663,
    pjPERTTaskEnterpriseProjectFlag16 = 188744664,
    pjPERTTaskEnterpriseProjectFlag17 = 188744665,
    pjPERTTaskEnterpriseProjectFlag18 = 188744666,
    pjPERTTaskEnterpriseProjectFlag19 = 188744667,
    pjPERTTaskEnterpriseProjectFlag20 = 188744668,
    pjPERTTaskEnterpriseProjectNumber1 = 188744689,
    pjPERTTaskEnterpriseProjectNumber2 = 188744690,
    pjPERTTaskEnterpriseProjectNumber3 = 188744691,
    pjPERTTaskEnterpriseProjectNumber4 = 188744692,
    pjPERTTaskEnterpriseProjectNumber5 = 188744693,
    pjPERTTaskEnterpriseProjectNumber6 = 188744694,
    pjPERTTaskEnterpriseProjectNumber7 = 188744695,
    pjPERTTaskEnterpriseProjectNumber8 = 188744696,
    pjPERTTaskEnterpriseProjectNumber9 = 188744697,
    pjPERTTaskEnterpriseProjectNumber10 = 188744698,
    pjPERTTaskEnterpriseProjectNumber11 = 188744699,
    pjPERTTaskEnterpriseProjectNumber12 = 188744700,
    pjPERTTaskEnterpriseProjectNumber13 = 188744701,
    pjPERTTaskEnterpriseProjectNumber14 = 188744702,
    pjPERTTaskEnterpriseProjectNumber15 = 188744703,
    pjPERTTaskEnterpriseProjectNumber16 = 188744704,
    pjPERTTaskEnterpriseProjectNumber17 = 188744705,
    pjPERTTaskEnterpriseProjectNumber18 = 188744706,
    pjPERTTaskEnterpriseProjectNumber19 = 188744707,
    pjPERTTaskEnterpriseProjectNumber20 = 188744708,
    pjPERTTaskEnterpriseProjectNumber21 = 188744709,
    pjPERTTaskEnterpriseProjectNumber22 = 188744710,
    pjPERTTaskEnterpriseProjectNumber23 = 188744711,
    pjPERTTaskEnterpriseProjectNumber24 = 188744712,
    pjPERTTaskEnterpriseProjectNumber25 = 188744713,
    pjPERTTaskEnterpriseProjectNumber26 = 188744714,
    pjPERTTaskEnterpriseProjectNumber27 = 188744715,
    pjPERTTaskEnterpriseProjectNumber28 = 188744716,
    pjPERTTaskEnterpriseProjectNumber29 = 188744717,
    pjPERTTaskEnterpriseProjectNumber30 = 188744718,
    pjPERTTaskEnterpriseProjectNumber31 = 188744719,
    pjPERTTaskEnterpriseProjectNumber32 = 188744720,
    pjPERTTaskEnterpriseProjectNumber33 = 188744721,
    pjPERTTaskEnterpriseProjectNumber34 = 188744722,
    pjPERTTaskEnterpriseProjectNumber35 = 188744723,
    pjPERTTaskEnterpriseProjectNumber36 = 188744724,
    pjPERTTaskEnterpriseProjectNumber37 = 188744725,
    pjPERTTaskEnterpriseProjectNumber38 = 188744726,
    pjPERTTaskEnterpriseProjectNumber39 = 188744727,
    pjPERTTaskEnterpriseProjectNumber40 = 188744728,
    pjPERTTaskEnterpriseProjectText1 = 188744729,
    pjPERTTaskEnterpriseProjectText2 = 188744730,
    pjPERTTaskEnterpriseProjectText3 = 188744731,
    pjPERTTaskEnterpriseProjectText4 = 188744732,
    pjPERTTaskEnterpriseProjectText5 = 188744733,
    pjPERTTaskEnterpriseProjectText6 = 188744734,
    pjPERTTaskEnterpriseProjectText7 = 188744735,
    pjPERTTaskEnterpriseProjectText8 = 188744736,
    pjPERTTaskEnterpriseProjectText9 = 188744737,
    pjPERTTaskEnterpriseProjectText10 = 188744738,
    pjPERTTaskEnterpriseProjectText11 = 188744739,
    pjPERTTaskEnterpriseProjectText12 = 188744740,
    pjPERTTaskEnterpriseProjectText13 = 188744741,
    pjPERTTaskEnterpriseProjectText14 = 188744742,
    pjPERTTaskEnterpriseProjectText15 = 188744743,
    pjPERTTaskEnterpriseProjectText16 = 188744744,
    pjPERTTaskEnterpriseProjectText17 = 188744745,
    pjPERTTaskEnterpriseProjectText18 = 188744746,
    pjPERTTaskEnterpriseProjectText19 = 188744747,
    pjPERTTaskEnterpriseProjectText20 = 188744748,
    pjPERTTaskEnterpriseProjectText21 = 188744749,
    pjPERTTaskEnterpriseProjectText22 = 188744750,
    pjPERTTaskEnterpriseProjectText23 = 188744751,
    pjPERTTaskEnterpriseProjectText24 = 188744752,
    pjPERTTaskEnterpriseProjectText25 = 188744753,
    pjPERTTaskEnterpriseProjectText26 = 188744754,
    pjPERTTaskEnterpriseProjectText27 = 188744755,
    pjPERTTaskEnterpriseProjectText28 = 188744756,
    pjPERTTaskEnterpriseProjectText29 = 188744757,
    pjPERTTaskEnterpriseProjectText30 = 188744758,
    pjPERTTaskEnterpriseProjectText31 = 188744759,
    pjPERTTaskEnterpriseProjectText32 = 188744760,
    pjPERTTaskEnterpriseProjectText33 = 188744761,
    pjPERTTaskEnterpriseProjectText34 = 188744762,
    pjPERTTaskEnterpriseProjectText35 = 188744763,
    pjPERTTaskEnterpriseProjectText36 = 188744764,
    pjPERTTaskEnterpriseProjectText37 = 188744765,
    pjPERTTaskEnterpriseProjectText38 = 188744766,
    pjPERTTaskEnterpriseProjectText39 = 188744767,
    pjPERTTaskEnterpriseProjectText40 = 188744768,
    pjPERTTaskResourceEnterpriseOutlineCode1 = 188744769,
    pjPERTTaskResourceEnterpriseOutlineCode2 = 188744770,
    pjPERTTaskResourceEnterpriseOutlineCode3 = 188744771,
    pjPERTTaskResourceEnterpriseOutlineCode4 = 188744772,
    pjPERTTaskResourceEnterpriseOutlineCode5 = 188744773,
    pjPERTTaskResourceEnterpriseOutlineCode6 = 188744774,
    pjPERTTaskResourceEnterpriseOutlineCode7 = 188744775,
    pjPERTTaskResourceEnterpriseOutlineCode8 = 188744776,
    pjPERTTaskResourceEnterpriseOutlineCode9 = 188744777,
    pjPERTTaskResourceEnterpriseOutlineCode10 = 188744778,
    pjPERTTaskResourceEnterpriseOutlineCode11 = 188744779,
    pjPERTTaskResourceEnterpriseOutlineCode12 = 188744780,
    pjPERTTaskResourceEnterpriseOutlineCode13 = 188744781,
    pjPERTTaskResourceEnterpriseOutlineCode14 = 188744782,
    pjPERTTaskResourceEnterpriseOutlineCode15 = 188744783,
    pjPERTTaskResourceEnterpriseOutlineCode16 = 188744784,
    pjPERTTaskResourceEnterpriseOutlineCode17 = 188744785,
    pjPERTTaskResourceEnterpriseOutlineCode18 = 188744786,
    pjPERTTaskResourceEnterpriseOutlineCode19 = 188744787,
    pjPERTTaskResourceEnterpriseOutlineCode20 = 188744788,
    pjPERTTaskResourceEnterpriseOutlineCode21 = 188744789,
    pjPERTTaskResourceEnterpriseOutlineCode22 = 188744790,
    pjPERTTaskResourceEnterpriseOutlineCode23 = 188744791,
    pjPERTTaskResourceEnterpriseOutlineCode24 = 188744792,
    pjPERTTaskResourceEnterpriseOutlineCode25 = 188744793,
    pjPERTTaskResourceEnterpriseOutlineCode26 = 188744794,
    pjPERTTaskResourceEnterpriseOutlineCode27 = 188744795,
    pjPERTTaskResourceEnterpriseOutlineCode28 = 188744796,
    pjPERTTaskResourceEnterpriseOutlineCode29 = 188744797,
    pjPERTTaskResourceEnterpriseOutlineCode30 = 188744798,
    pjPERTTaskPhysicalPercentComplete = 188744799,
    pjPERTTaskDemandedRequested = 188744800,
    pjPERTTaskEarnedValueMethod = 188744802,
    pjPERTTasknull_prop = 188744808,
    pjPERTTaskResourceEnterpriseMultiValue20 = 188744809,
    pjPERTTaskResourceEnterpriseMultiValue21 = 188744810,
    pjPERTTaskResourceEnterpriseMultiValue22 = 188744811,
    pjPERTTaskResourceEnterpriseMultiValue23 = 188744812,
    pjPERTTaskResourceEnterpriseMultiValue24 = 188744813,
    pjPERTTaskResourceEnterpriseMultiValue25 = 188744814,
    pjPERTTaskResourceEnterpriseMultiValue26 = 188744815,
    pjPERTTaskResourceEnterpriseMultiValue27 = 188744816,
    pjPERTTaskResourceEnterpriseMultiValue28 = 188744817,
    pjPERTTaskResourceEnterpriseMultiValue29 = 188744818,
    pjPERTTaskActualWorkProtected = 188744819,
    pjPERTTaskActualOvertimeWorkProtected = 188744820,
    pjPERTTaskGuid = 188744823,
    pjPERTTaskCalendarGuid = 188744824,
    pjPERTTaskDeliverableGuid = 188744826,
    pjPERTTaskDeliverableType = 188744827,
    pjPERTTaskDeliverableStart = 188744832,
    pjPERTTaskDeliverableFinish = 188744833,
    pjPERTTaskIsPublished = 188744845,
    pjPERTTaskStatusManagerName = 188744846,
    pjPERTTaskErrorMessage = 188744847,
    pjPERTTaskAssignment_Owner = 188744850,
    pjPERTTaskBudgetWork = 188744851,
    pjPERTTaskBudgetCost = 188744852,
    pjPERTTaskBaselineFixedCostAccrual = 188744853,
    pjPERTTaskBaselineDeliverableStart = 188744854,
    pjPERTTaskBaselineDeliverableFinish = 188744855,
    pjPERTTaskBaselineBudgetWork = 188744856,
    pjPERTTaskBaselineBudgetCost = 188744857,
    pjPERTTaskBaseline1FixedCostAccrual = 188744860,
    pjPERTTaskBaseline1DeliverableStart = 188744861,
    pjPERTTaskBaseline1DeliverableFinish = 188744862,
    pjPERTTaskBaseline1BudgetWork = 188744863,
    pjPERTTaskBaseline1BudgetCost = 188744864,
    pjPERTTaskBaseline2FixedCostAccrual = 188744867,
    pjPERTTaskBaseline2DeliverableStart = 188744868,
    pjPERTTaskBaseline2DeliverableFinish = 188744869,
    pjPERTTaskBaseline2BudgetWork = 188744870,
    pjPERTTaskBaseline2BudgetCost = 188744871,
    pjPERTTaskBaseline3FixedCostAccrual = 188744874,
    pjPERTTaskBaseline3DeliverableStart = 188744875,
    pjPERTTaskBaseline3DeliverableFinish = 188744876,
    pjPERTTaskBaseline3BudgetWork = 188744877,
    pjPERTTaskBaseline3BudgetCost = 188744878,
    pjPERTTaskBaseline4FixedCostAccrual = 188744881,
    pjPERTTaskBaseline4DeliverableStart = 188744882,
    pjPERTTaskBaseline4DeliverableFinish = 188744883,
    pjPERTTaskBaseline4BudgetWork = 188744884,
    pjPERTTaskBaseline4BudgetCost = 188744885,
    pjPERTTaskBaseline5FixedCostAccrual = 188744888,
    pjPERTTaskBaseline5DeliverableStart = 188744889,
    pjPERTTaskBaseline5DeliverableFinish = 188744890,
    pjPERTTaskBaseline5BudgetWork = 188744891,
    pjPERTTaskBaseline5BudgetCost = 188744892,
    pjPERTTaskBaseline6FixedCostAccrual = 188744895,
    pjPERTTaskBaseline6DeliverableStart = 188744896,
    pjPERTTaskBaseline6DeliverableFinish = 188744897,
    pjPERTTaskBaseline6BudgetWork = 188744898,
    pjPERTTaskBaseline6BudgetCost = 188744899,
    pjPERTTaskBaseline7FixedCostAccrual = 188744902,
    pjPERTTaskBaseline7DeliverableStart = 188744903,
    pjPERTTaskBaseline7DeliverableFinish = 188744904,
    pjPERTTaskBaseline7BudgetWork = 188744905,
    pjPERTTaskBaseline7BudgetCost = 188744906,
    pjPERTTaskBaseline8FixedCostAccrual = 188744909,
    pjPERTTaskBaseline8DeliverableStart = 188744910,
    pjPERTTaskBaseline8DeliverableFinish = 188744911,
    pjPERTTaskBaseline8BudgetWork = 188744912,
    pjPERTTaskBaseline8BudgetCost = 188744913,
    pjPERTTaskBaseline9FixedCostAccrual = 188744916,
    pjPERTTaskBaseline9DeliverableStart = 188744917,
    pjPERTTaskBaseline9DeliverableFinish = 188744918,
    pjPERTTaskBaseline9BudgetWork = 188744919,
    pjPERTTaskBaseline9BudgetCost = 188744920,
    pjPERTTaskBaseline10FixedCostAccrual = 188744923,
    pjPERTTaskBaseline10DeliverableStart = 188744924,
    pjPERTTaskBaseline10DeliverableFinish = 188744925,
    pjPERTTaskBaseline10BudgetWork = 188744926,
    pjPERTTaskBaseline10BudgetCost = 188744927,
    pjPERTTaskDeliverableName = 188744956,
    pjPERTTaskActive = 188744959,
    pjPERTTaskManual = 188744960,
    pjPERTTaskPlaceholder = 188744961,
    pjPERTTaskWarning = 188744962,
    pjPERTTaskStartText = 188744965,
    pjPERTTaskFinishText = 188744966,
    pjPERTTaskDurationText = 188744967,
    pjPERTTaskBaselineStartText = 188744979,
    pjPERTTaskBaselineFinishText = 188744980,
    pjPERTTaskBaselineDurationText = 188744981,
    pjPERTTaskBaseline1StartText = 188744982,
    pjPERTTaskBaseline1FinishText = 188744983,
    pjPERTTaskBaseline1DurationText = 188744984,
    pjPERTTaskBaseline2StartText = 188744985,
    pjPERTTaskBaseline2FinishText = 188744986,
    pjPERTTaskBaseline2DurationText = 188744987,
    pjPERTTaskBaseline3StartText = 188744988,
    pjPERTTaskBaseline3FinishText = 188744989,
    pjPERTTaskBaseline3DurationText = 188744990,
    pjPERTTaskBaseline4StartText = 188744991,
    pjPERTTaskBaseline4FinishText = 188744992,
    pjPERTTaskBaseline4DurationText = 188744993,
    pjPERTTaskBaseline5StartText = 188744994,
    pjPERTTaskBaseline5FinishText = 188744995,
    pjPERTTaskBaseline5DurationText = 188744996,
    pjPERTTaskBaseline6StartText = 188744997,
    pjPERTTaskBaseline6FinishText = 188744998,
    pjPERTTaskBaseline6DurationText = 188744999,
    pjPERTTaskBaseline7StartText = 188745000,
    pjPERTTaskBaseline7FinishText = 188745001,
    pjPERTTaskBaseline7DurationText = 188745002,
    pjPERTTaskBaseline8StartText = 188745003,
    pjPERTTaskBaseline8FinishText = 188745004,
    pjPERTTaskBaseline8DurationText = 188745005,
    pjPERTTaskBaseline9StartText = 188745006,
    pjPERTTaskBaseline9FinishText = 188745007,
    pjPERTTaskBaseline9DurationText = 188745008,
    pjPERTTaskBaseline10StartText = 188745009,
    pjPERTTaskBaseline10FinishText = 188745010,
    pjPERTTaskBaseline10DurationText = 188745011,
    pjPERTTaskIgnoreWarnings = 188745012,
    pjPERTTaskAssignmentPeakUnits = 188745015,
    pjPERTTaskNotes = 188743695
};

enum __declspec(uuid("626f39f0-922b-11cf-982c-00aa00322803"))
PjPERTBoxSize
{
    pjIDOnly = 0,
    pjSmall = 1,
    pjMedium = 2,
    pjLarge = 3
};

enum __declspec(uuid("a453a8c0-922b-11cf-982c-00aa00322803"))
PjPERTBoxStyle
{
    pjPlainBox = 0,
    pjThickBox = 1,
    pjShadowBox = 2,
    pjDottedBox = 3,
    pjFrame = 4,
    pjGrayFrame = 5,
    pjPatternFrame = 6,
    pjMarquee = 7
};

enum __declspec(uuid("dbfcf830-922b-11cf-982c-00aa00322803"))
PjPlacement
{
    pjBefore = 0,
    pjAfter = 1,
    pjBeforeWithSpace = 2,
    pjAfterWithSpace = 3
};

enum __declspec(uuid("0f0da940-922c-11cf-982c-00aa00322803"))
PjPoolAction
{
    pjPoolTakesPrecedence = 1,
    pjSharersTakePrecedence = 2,
    pjOpenSharer = 3,
    pjOpenAllSharers = 4,
    pjUnlinkSharer = 5
};

enum __declspec(uuid("4cd84e40-922c-11cf-982c-00aa00322803"))
PjPriority
{
    pjPriorityDoNotLevel = 9,
    pjPriorityHighest = 8,
    pjPriorityVeryHigh = 7,
    pjPriorityHigher = 6,
    pjPriorityHigh = 5,
    pjPriorityMedium = 4,
    pjPriorityLow = 3,
    pjPriorityLower = 2,
    pjPriorityVeryLow = 1,
    pjPriorityLowest = 0
};

enum __declspec(uuid("abae6140-922c-11cf-982c-00aa00322803"))
PjProjectUpdate
{
    pj0or100Percent = 0,
    pj0to100Percent = 1,
    pjReschedule = 2
};

enum __declspec(uuid("de434c20-922c-11cf-982c-00aa00322803"))
PjPublishAction
{
    pjCancel = 1,
    pjSendPublisher = 2
};

enum __declspec(uuid("134f4f70-922d-11cf-982c-00aa00322803"))
PjEditionUpdate
{
    pjAutomaticUpdate = 4,
    pjManualUpdate = 5
};

enum __declspec(uuid("58e290f0-922d-11cf-982c-00aa00322803"))
PjResAssignOperation
{
    pjAssign = 0,
    pjRemove = 1,
    pjReplace = 2,
    pjChange = 3
};

enum __declspec(uuid("492b45c0-922e-11cf-982c-00aa00322803"))
PjResourceGraphStyle
{
    pjBar = 0,
    pjArea = 1,
    pjStep = 2,
    pjLineGraph = 3,
    pjStepLine = 4,
    pjDoNotShow = 5
};

enum __declspec(uuid("b8ebea20-922e-11cf-982c-00aa00322803"))
PjSaveType
{
    pjDoNotSave = 0,
    pjSave = 1,
    pjPromptSave = 2
};

enum __declspec(uuid("31205000-922f-11cf-982c-00aa00322803"))
PjSaveBaselineFrom
{
    pjCopyCurrent = 0,
    pjCopyBaseline = 1,
    pjCopyStart_Finish1 = 2,
    pjCopyStart_Finish2 = 3,
    pjCopyStart_Finish3 = 4,
    pjCopyStart_Finish4 = 5,
    pjCopyStart_Finish5 = 6,
    pjCopyStart_Finish6 = 7,
    pjCopyStart_Finish7 = 8,
    pjCopyStart_Finish8 = 9,
    pjCopyStart_Finish9 = 10,
    pjCopyStart_Finish10 = 11,
    pjCopyBaseline1 = 12,
    pjCopyBaseline2 = 13,
    pjCopyBaseline3 = 14,
    pjCopyBaseline4 = 15,
    pjCopyBaseline5 = 16,
    pjCopyBaseline6 = 17,
    pjCopyBaseline7 = 18,
    pjCopyBaseline8 = 19,
    pjCopyBaseline9 = 20,
    pjCopyBaseline10 = 21
};

enum __declspec(uuid("6fbf5c10-922f-11cf-982c-00aa00322803"))
PjSaveBaselineTo
{
    pjIntoBaseline = 0,
    pjIntoStart_Finish1 = 1,
    pjIntoStart_Finish2 = 2,
    pjIntoStart_Finish3 = 3,
    pjIntoStart_Finish4 = 4,
    pjIntoStart_Finish5 = 5,
    pjIntoStart_Finish6 = 6,
    pjIntoStart_Finish7 = 7,
    pjIntoStart_Finish8 = 8,
    pjIntoStart_Finish9 = 9,
    pjIntoStart_Finish10 = 10,
    pjIntoBaseline1 = 11,
    pjIntoBaseline2 = 12,
    pjIntoBaseline3 = 13,
    pjIntoBaseline4 = 14,
    pjIntoBaseline5 = 15,
    pjIntoBaseline6 = 16,
    pjIntoBaseline7 = 17,
    pjIntoBaseline8 = 18,
    pjIntoBaseline9 = 19,
    pjIntoBaseline10 = 20
};

enum __declspec(uuid("d9d2cd20-922f-11cf-982c-00aa00322803"))
PjScheduleProjectFrom
{
    pjProjectStart = 1,
    pjProjectFinish = 2
};

enum __declspec(uuid("115c05a0-9230-11cf-982c-00aa00322803"))
PjViewScreen
{
    pjGantt = 1,
    pjNetworkDiagram = 2,
    pjRelationshipDiagram = 3,
    pjTaskForm = 4,
    pjTaskSheet = 5,
    pjResourceForm = 6,
    pjResourceSheet = 7,
    pjResourceGraph = 8,
    pjRSVDoNotUse = 9,
    pjTaskDetailsForm = 10,
    pjTaskNameForm = 11,
    pjResourceNameForm = 12,
    pjCalendar = 13,
    pjTaskUsage = 14,
    pjResourceUsage = 15,
    pjTimeline = 16,
    pjResourceScheduling = 17
};

enum __declspec(uuid("75171e60-9230-11cf-982c-00aa00322803"))
PjShape
{
    pjOLEObject = 1,
    pjLine = 2,
    pjArrow = 3,
    pjRectangle = 4,
    pjEllipse = 5,
    pjArc = 6,
    pjPolygon = 7,
    pjTextBox = 8
};

enum __declspec(uuid("e466aee0-9230-11cf-982c-00aa00322803"))
PjSubscribeAction
{
    pjCancelSubscribe = 1,
    pjUpdateSubscriber = 2
};

enum __declspec(uuid("17095a70-9231-11cf-982c-00aa00322803"))
PjSubscribeFormat
{
    pjSubscribeToText = 1,
    pjSubscribeToPicture = 2
};

enum __declspec(uuid("4f795040-9231-11cf-982c-00aa00322803"))
PjTaskLinkType
{
    pjFinishToFinish = 0,
    pjFinishToStart = 1,
    pjStartToFinish = 2,
    pjStartToStart = 3
};

enum __declspec(uuid("adb236e0-119d-11d0-a533-00a0c904de55"))
PjTaskFixedType
{
    pjFixedUnits = 0,
    pjFixedDuration = 1,
    pjFixedWork = 2
};

enum __declspec(uuid("08368d50-5222-11d0-b6d8-00a0c904de5c"))
PjWorkContourType
{
    pjFlat = 0,
    pjBackLoaded = 1,
    pjFrontLoaded = 2,
    pjDoublePeak = 3,
    pjEarlyPeak = 4,
    pjLatePeak = 5,
    pjBell = 6,
    pjTurtle = 7,
    pjContour = 8
};

enum __declspec(uuid("2ae031f0-923b-11cf-982c-00aa00322803"))
PjInformationTab
{
    pjTaskGeneralTab = 0,
    pjTaskPredecessorsTab = 1,
    pjTaskResourcesTab = 2,
    pjTaskAdvancedTab = 3,
    pjTaskNotesTab = 4,
    pjResourceGeneralTab = 0,
    pjResourceWorkingTimeTab = 1,
    pjResourceCostsTab = 2,
    pjResourceNotesTab = 3,
    pjAssignmentGeneralTab = 0,
    pjAssignmentTrackingTab = 1,
    pjAssignmentNotesTab = 2,
    pjResourceCustomFieldsTab = 4,
    pjTaskCustomFieldsTab = 5
};

enum __declspec(uuid("669ba740-923b-11cf-982c-00aa00322803"))
PjTextItem
{
    pjAll = 0,
    pjNoncritical = 1,
    pjCritical = 2,
    pjMilestone = 3,
    pjSummary = 4,
    pjProjectSummary = 5,
    pjMarked = 6,
    pjTaskFilterHighlight = 7,
    pjTaskRowColumnTitles = 8,
    pjGanttMajorTimescale = 9,
    pjGanttMinorTimescale = 10,
    pjGanttExternalTask = 16,
    pjBarTextLeft = 11,
    pjBarTextRight = 12,
    pjBarTextTop = 13,
    pjBarTextBottom = 14,
    pjBarTextInside = 15,
    pjCalendarMonthlyTitles = 8,
    pjCalendarExternalTask = 17,
    pjDailyTitles = 9,
    pjWeeklyTitles = 10,
    pjMonthPreviews = 11,
    pjDateBoxTopRight = 12,
    pjDateBoxTopLeft = 13,
    pjDateBoxBottomRight = 14,
    pjDateBoxBottomLeft = 15,
    pjTaskSheetExternalTask = 9,
    pjTaskUsageExternalTask = 11,
    pjAllocated = 1,
    pjOverallocated = 2,
    pjGraphMajorTimescale = 3,
    pjGraphMinorTimescale = 4,
    pjTickLabels = 5,
    pjLegendLabels = 6,
    pjResourceFilterHighlight = 3,
    pjResourceRowColumnTitles = 4,
    pjTaskUsageAssignmentRow = 9,
    pjTaskMajorTimescale = 10,
    pjTaskMinorTimescale = 11,
    pjResourceUsageAssignmentRow = 5,
    pjResourceMajorTimescale = 6,
    pjResourceMinorTimescale = 7
};

enum __declspec(uuid("0af8c240-923c-11cf-982c-00aa00322803"))
PjTimescaledData
{
    pjWork = 0,
    pjCost = 1,
    pjCumulativeWork = 2,
    pjCumulativeCost = 3,
    pjActualWork = 4,
    pjActualOvertimeWork = 5,
    pjOvertimeWork = 6,
    pjBaselineWork = 7,
    pjOverallocation = 8,
    pjFixedCost = 9,
    pjActualCost = 10,
    pjBaselineCost = 11,
    pjRegularWork = 12,
    pjBCWS = 13,
    pjBCWP = 14,
    pjACWP = 15,
    pjSV = 16,
    pjCV = 17,
    pjPercentAllocation = 18,
    pjPeakUnits = 19,
    pjRemainingAvailability = 20,
    pjPctComplete = 21,
    pjCumPctComplete = 22,
    pjAllTaskRows = 23,
    pjAllResourceRows = 23,
    pjAllAssignmentRows = 24,
    pjUnitAvailability = 25,
    pjWorkAvailability = 26,
    pjBaseline1Work = 27,
    pjBaseline1Cost = 28,
    pjBaseline2Work = 29,
    pjBaseline2Cost = 30,
    pjBaseline3Work = 31,
    pjBaseline3Cost = 32,
    pjBaseline4Work = 33,
    pjBaseline4Cost = 34,
    pjBaseline5Work = 35,
    pjBaseline5Cost = 36,
    pjBaseline6Work = 37,
    pjBaseline6Cost = 38,
    pjBaseline7Work = 39,
    pjBaseline7Cost = 40,
    pjBaseline8Work = 41,
    pjBaseline8Cost = 42,
    pjBaseline9Work = 43,
    pjBaseline9Cost = 44,
    pjBaseline10Work = 45,
    pjBaseline10Cost = 46,
    pjActualFixedCost = 47,
    pjCPI = 48,
    pjSPI = 49,
    pjCVP = 50,
    pjSVP = 51,
    pjActualWorkProtected = 52,
    pjActualOvertimeWorkProtected = 53,
    pjBudgetWork = 54,
    pjBudgetCost = 55,
    pjBaselineBudgetWork = 56,
    pjBaselineBudgetCost = 57,
    pjBaseline1BudgetWork = 58,
    pjBaseline1BudgetCost = 59,
    pjBaseline2BudgetWork = 60,
    pjBaseline2BudgetCost = 61,
    pjBaseline3BudgetWork = 62,
    pjBaseline3BudgetCost = 63,
    pjBaseline4BudgetWork = 64,
    pjBaseline4BudgetCost = 65,
    pjBaseline5BudgetWork = 66,
    pjBaseline5BudgetCost = 67,
    pjBaseline6BudgetWork = 68,
    pjBaseline6BudgetCost = 69,
    pjBaseline7BudgetWork = 70,
    pjBaseline7BudgetCost = 71,
    pjBaseline8BudgetWork = 72,
    pjBaseline8BudgetCost = 73,
    pjBaseline9BudgetWork = 74,
    pjBaseline9BudgetCost = 75,
    pjBaseline10BudgetWork = 76,
    pjBaseline10BudgetCost = 77,
    pjCumulativeActualWork = 78,
    pjRemainingCumulativeActualWork = 79,
    pjRemainingCumulativeWork = 80,
    pjRemainingTasks = 81,
    pjRemainingActualTasks = 82,
    pjBaselineRemainingCumulativeWork = 83,
    pjBaseline1RemainingCumulativeWork = 84,
    pjBaseline2RemainingCumulativeWork = 85,
    pjBaseline3RemainingCumulativeWork = 86,
    pjBaseline4RemainingCumulativeWork = 87,
    pjBaseline5RemainingCumulativeWork = 88,
    pjBaseline6RemainingCumulativeWork = 89,
    pjBaseline7RemainingCumulativeWork = 90,
    pjBaseline8RemainingCumulativeWork = 91,
    pjBaseline9RemainingCumulativeWork = 92,
    pjBaseline10RemainingCumulativeWork = 93,
    pjBaselineRemainingTasks = 94,
    pjBaseline1RemainingTasks = 95,
    pjBaseline2RemainingTasks = 96,
    pjBaseline3RemainingTasks = 97,
    pjBaseline4RemainingTasks = 98,
    pjBaseline5RemainingTasks = 99,
    pjBaseline6RemainingTasks = 100,
    pjBaseline7RemainingTasks = 101,
    pjBaseline8RemainingTasks = 102,
    pjBaseline9RemainingTasks = 103,
    pjBaseline10RemainingTasks = 104,
    pjBaselineCumulativeWork = 105,
    pjBaseline1CumulativeWork = 106,
    pjBaseline2CumulativeWork = 107,
    pjBaseline3CumulativeWork = 108,
    pjBaseline4CumulativeWork = 109,
    pjBaseline5CumulativeWork = 110,
    pjBaseline6CumulativeWork = 111,
    pjBaseline7CumulativeWork = 112,
    pjBaseline8CumulativeWork = 113,
    pjBaseline9CumulativeWork = 114,
    pjBaseline10CumulativeWork = 115
};

enum __declspec(uuid("39a7d7b0-923c-11cf-982c-001100322803"))
PjTimescaleUnit
{
    pjTimescaleYears = 0,
    pjTimescaleQuarters = 1,
    pjTimescaleMonths = 2,
    pjTimescaleWeeks = 3,
    pjTimescaleDays = 4,
    pjTimescaleHours = 5,
    pjTimescaleMinutes = 6,
    pjTimescaleThirdsOfMonths = 7,
    pjTimescaleHalfYears = 8,
    pjTimescaleNone = 255
};

enum __declspec(uuid("203b6610-0118-11d0-8205-00aa004428a2"))
PjTaskTimescaledData
{
    pjTaskTimescaledWork = 0,
    pjTaskTimescaledRegularWork = 166,
    pjTaskTimescaledOvertimeWork = 163,
    pjTaskTimescaledActualWork = 2,
    pjTaskTimescaledActualOvertimeWork = 164,
    pjTaskTimescaledCumulativeWork = 176,
    pjTaskTimescaledBaselineWork = 1,
    pjTaskTimescaledOverallocation = 167,
    pjTaskTimescaledCost = 5,
    pjTaskTimescaledFixedCost = 8,
    pjTaskTimescaledActualCost = 7,
    pjTaskTimescaledBaselineCost = 6,
    pjTaskTimescaledCumulativeCost = 177,
    pjTaskTimescaledBCWS = 12,
    pjTaskTimescaledBCWP = 11,
    pjTaskTimescaledACWP = 120,
    pjTaskTimescaledSV = 13,
    pjTaskTimescaledCV = 83,
    pjTaskTimescaledPercentComplete = 32,
    pjTaskTimescaledCumulativePercentComplete = 240,
    pjTaskTimescaledBaseline1Work = 485,
    pjTaskTimescaledBaseline1Cost = 484,
    pjTaskTimescaledBaseline2Work = 496,
    pjTaskTimescaledBaseline2Cost = 495,
    pjTaskTimescaledBaseline3Work = 507,
    pjTaskTimescaledBaseline3Cost = 506,
    pjTaskTimescaledBaseline4Work = 518,
    pjTaskTimescaledBaseline4Cost = 517,
    pjTaskTimescaledBaseline5Work = 529,
    pjTaskTimescaledBaseline5Cost = 528,
    pjTaskTimescaledBaseline6Work = 547,
    pjTaskTimescaledBaseline6Cost = 546,
    pjTaskTimescaledBaseline7Work = 558,
    pjTaskTimescaledBaseline7Cost = 557,
    pjTaskTimescaledBaseline8Work = 569,
    pjTaskTimescaledBaseline8Cost = 568,
    pjTaskTimescaledBaseline9Work = 580,
    pjTaskTimescaledBaseline9Cost = 579,
    pjTaskTimescaledBaseline10Work = 591,
    pjTaskTimescaledBaseline10Cost = 590,
    pjTaskTimescaledCPI = 537,
    pjTaskTimescaledSPI = 538,
    pjTaskTimescaledCVP = 539,
    pjTaskTimescaledSVP = 540,
    pjTaskTimescaledActualFixedCost = 171,
    pjTaskTimescaledActualWorkProtected = 1139,
    pjTaskTimescaledActualOvertimeWorkProtected = 1140,
    pjTaskTimescaledBudgetWork = 1172,
    pjTaskTimescaledBudgetCost = 1173,
    pjTaskTimescaledBaselineBudgetWork = 1177,
    pjTaskTimescaledBaselineBudgetCost = 1178,
    pjTaskTimescaledBaseline1BudgetWork = 1184,
    pjTaskTimescaledBaseline1BudgetCost = 1185,
    pjTaskTimescaledBaseline2BudgetWork = 1191,
    pjTaskTimescaledBaseline2BudgetCost = 1192,
    pjTaskTimescaledBaseline3BudgetWork = 1198,
    pjTaskTimescaledBaseline3BudgetCost = 1199,
    pjTaskTimescaledBaseline4BudgetWork = 1205,
    pjTaskTimescaledBaseline4BudgetCost = 1206,
    pjTaskTimescaledBaseline5BudgetWork = 1212,
    pjTaskTimescaledBaseline5BudgetCost = 1213,
    pjTaskTimescaledBaseline6BudgetWork = 1219,
    pjTaskTimescaledBaseline6BudgetCost = 1220,
    pjTaskTimescaledBaseline7BudgetWork = 1226,
    pjTaskTimescaledBaseline7BudgetCost = 1227,
    pjTaskTimescaledBaseline8BudgetWork = 1233,
    pjTaskTimescaledBaseline8BudgetCost = 1234,
    pjTaskTimescaledBaseline9BudgetWork = 1240,
    pjTaskTimescaledBaseline9BudgetCost = 1241,
    pjTaskTimescaledBaseline10BudgetWork = 1247,
    pjTaskTimescaledBaseline10BudgetCost = 1248,
    pjTaskTimescaledCumulativeActualWork = 1341,
    pjTaskTimescaledRemainingCumulativeActualWork = 1342,
    pjTaskTimescaledRemainingCumulativeWork = 1343,
    pjTaskTimescaledRemainingTasks = 1344,
    pjTaskTimescaledRemainingActualTasks = 1345,
    pjTaskTimescaledBaselineRemainingCumulativeWork = 1346,
    pjTaskTimescaledBaseline1RemainingCumulativeWork = 1347,
    pjTaskTimescaledBaseline2RemainingCumulativeWork = 1348,
    pjTaskTimescaledBaseline3RemainingCumulativeWork = 1349,
    pjTaskTimescaledBaseline4RemainingCumulativeWork = 1350,
    pjTaskTimescaledBaseline5RemainingCumulativeWork = 1351,
    pjTaskTimescaledBaseline6RemainingCumulativeWork = 1352,
    pjTaskTimescaledBaseline7RemainingCumulativeWork = 1353,
    pjTaskTimescaledBaseline8RemainingCumulativeWork = 1354,
    pjTaskTimescaledBaseline9RemainingCumulativeWork = 1355,
    pjTaskTimescaledBaseline10RemainingCumulativeWork = 1356,
    pjTaskTimescaledBaselineRemainingTasks = 1357,
    pjTaskTimescaledBaseline1RemainingTasks = 1358,
    pjTaskTimescaledBaseline2RemainingTasks = 1359,
    pjTaskTimescaledBaseline3RemainingTasks = 1360,
    pjTaskTimescaledBaseline4RemainingTasks = 1361,
    pjTaskTimescaledBaseline5RemainingTasks = 1362,
    pjTaskTimescaledBaseline6RemainingTasks = 1363,
    pjTaskTimescaledBaseline7RemainingTasks = 1364,
    pjTaskTimescaledBaseline8RemainingTasks = 1365,
    pjTaskTimescaledBaseline9RemainingTasks = 1366,
    pjTaskTimescaledBaseline10RemainingTasks = 1367,
    pjTaskTimescaledBaselineCumulativeWork = 1368,
    pjTaskTimescaledBaseline1CumulativeWork = 1369,
    pjTaskTimescaledBaseline2CumulativeWork = 1370,
    pjTaskTimescaledBaseline3CumulativeWork = 1371,
    pjTaskTimescaledBaseline4CumulativeWork = 1372,
    pjTaskTimescaledBaseline5CumulativeWork = 1373,
    pjTaskTimescaledBaseline6CumulativeWork = 1374,
    pjTaskTimescaledBaseline7CumulativeWork = 1375,
    pjTaskTimescaledBaseline8CumulativeWork = 1376,
    pjTaskTimescaledBaseline9CumulativeWork = 1377,
    pjTaskTimescaledBaseline10CumulativeWork = 1378
};

enum __declspec(uuid("8caa8fb0-0119-11d0-8205-00aa004428a2"))
PjResourceTimescaledData
{
    pjResourceTimescaledWork = 13,
    pjResourceTimescaledRegularWork = 38,
    pjResourceTimescaledOvertimeWork = 16,
    pjResourceTimescaledActualWork = 14,
    pjResourceTimescaledActualOvertimeWork = 39,
    pjResourceTimescaledCumulativeWork = 41,
    pjResourceTimescaledBaselineWork = 15,
    pjResourceTimescaledOverallocation = 42,
    pjResourceTimescaledPercentAllocation = 43,
    pjResourceTimescaledPeakUnits = 26,
    pjResourceTimescaledRemainingAvailability = 44,
    pjResourceTimescaledCost = 12,
    pjResourceTimescaledActualCost = 11,
    pjResourceTimescaledBaselineCost = 17,
    pjResourceTimescaledCumulativeCost = 50,
    pjResourceTimescaledBCWS = 51,
    pjResourceTimescaledBCWP = 52,
    pjResourceTimescaledACWP = 53,
    pjResourceTimescaledSV = 54,
    pjResourceTimescaledCV = 268,
    pjResourceTimescaledWorkAvailability = 45,
    pjResourceTimescaledUnitAvailability = 4,
    pjResourceTimescaledBaseline1Work = 342,
    pjResourceTimescaledBaseline1Cost = 343,
    pjResourceTimescaledBaseline2Work = 352,
    pjResourceTimescaledBaseline2Cost = 353,
    pjResourceTimescaledBaseline3Work = 362,
    pjResourceTimescaledBaseline3Cost = 363,
    pjResourceTimescaledBaseline4Work = 372,
    pjResourceTimescaledBaseline4Cost = 373,
    pjResourceTimescaledBaseline5Work = 382,
    pjResourceTimescaledBaseline5Cost = 383,
    pjResourceTimescaledBaseline6Work = 392,
    pjResourceTimescaledBaseline6Cost = 393,
    pjResourceTimescaledBaseline7Work = 402,
    pjResourceTimescaledBaseline7Cost = 403,
    pjResourceTimescaledBaseline8Work = 412,
    pjResourceTimescaledBaseline8Cost = 413,
    pjResourceTimescaledBaseline9Work = 422,
    pjResourceTimescaledBaseline9Cost = 423,
    pjResourceTimescaledBaseline10Work = 432,
    pjResourceTimescaledBaseline10Cost = 433,
    pjResourceTimescaledActualWorkProtected = 720,
    pjResourceTimescaledActualOvertimeWorkProtected = 721,
    pjResourceTimescaledBudgetWork = 754,
    pjResourceTimescaledBudgetCost = 755,
    pjResourceTimescaledBaselineBudgetWork = 757,
    pjResourceTimescaledBaselineBudgetCost = 758,
    pjResourceTimescaledBaseline1BudgetWork = 761,
    pjResourceTimescaledBaseline1BudgetCost = 762,
    pjResourceTimescaledBaseline2BudgetWork = 765,
    pjResourceTimescaledBaseline2BudgetCost = 766,
    pjResourceTimescaledBaseline3BudgetWork = 769,
    pjResourceTimescaledBaseline3BudgetCost = 770,
    pjResourceTimescaledBaseline4BudgetWork = 773,
    pjResourceTimescaledBaseline4BudgetCost = 774,
    pjResourceTimescaledBaseline5BudgetWork = 777,
    pjResourceTimescaledBaseline5BudgetCost = 778,
    pjResourceTimescaledBaseline6BudgetWork = 781,
    pjResourceTimescaledBaseline6BudgetCost = 782,
    pjResourceTimescaledBaseline7BudgetWork = 785,
    pjResourceTimescaledBaseline7BudgetCost = 786,
    pjResourceTimescaledBaseline8BudgetWork = 789,
    pjResourceTimescaledBaseline8BudgetCost = 790,
    pjResourceTimescaledBaseline9BudgetWork = 793,
    pjResourceTimescaledBaseline9BudgetCost = 794,
    pjResourceTimescaledBaseline10BudgetWork = 797,
    pjResourceTimescaledBaseline10BudgetCost = 798,
    pjResourceTimescaledCumulativeActualWork = 811,
    pjResourceTimescaledRemainingCumulativeActualWork = 812,
    pjResourceTimescaledRemainingCumulativeWork = 813,
    pjResourceTimescaledBaselineRemainingCumulativeWork = 814,
    pjResourceTimescaledBaseline1RemainingCumulativeWork = 815,
    pjResourceTimescaledBaseline2RemainingCumulativeWork = 816,
    pjResourceTimescaledBaseline3RemainingCumulativeWork = 817,
    pjResourceTimescaledBaseline4RemainingCumulativeWork = 818,
    pjResourceTimescaledBaseline5RemainingCumulativeWork = 819,
    pjResourceTimescaledBaseline6RemainingCumulativeWork = 820,
    pjResourceTimescaledBaseline7RemainingCumulativeWork = 821,
    pjResourceTimescaledBaseline8RemainingCumulativeWork = 822,
    pjResourceTimescaledBaseline9RemainingCumulativeWork = 823,
    pjResourceTimescaledBaseline10RemainingCumulativeWork = 824,
    pjResourceTimescaledBaselineCumulativeWork = 825,
    pjResourceTimescaledBaseline1CumulativeWork = 826,
    pjResourceTimescaledBaseline2CumulativeWork = 827,
    pjResourceTimescaledBaseline3CumulativeWork = 828,
    pjResourceTimescaledBaseline4CumulativeWork = 829,
    pjResourceTimescaledBaseline5CumulativeWork = 830,
    pjResourceTimescaledBaseline6CumulativeWork = 831,
    pjResourceTimescaledBaseline7CumulativeWork = 832,
    pjResourceTimescaledBaseline8CumulativeWork = 833,
    pjResourceTimescaledBaseline9CumulativeWork = 834,
    pjResourceTimescaledBaseline10CumulativeWork = 835
};

enum __declspec(uuid("97987800-0119-11d0-8205-00aa004428a2"))
PjAssignmentTimescaledData
{
    pjAssignmentTimescaledWork = 8,
    pjAssignmentTimescaledRegularWork = 11,
    pjAssignmentTimescaledOvertimeWork = 9,
    pjAssignmentTimescaledActualWork = 10,
    pjAssignmentTimescaledActualOvertimeWork = 13,
    pjAssignmentTimescaledCumulativeWork = 15,
    pjAssignmentTimescaledBaselineWork = 16,
    pjAssignmentTimescaledOverallocation = 17,
    pjAssignmentTimescaledPercentAllocation = 18,
    pjAssignmentTimescaledPeakUnits = 19,
    pjAssignmentTimescaledCost = 26,
    pjAssignmentTimescaledActualCost = 28,
    pjAssignmentTimescaledBaselineCost = 32,
    pjAssignmentTimescaledCumulativeCost = 33,
    pjAssignmentTimescaledBCWS = 34,
    pjAssignmentTimescaledBCWP = 35,
    pjAssignmentTimescaledACWP = 36,
    pjAssignmentTimescaledSV = 37,
    pjAssignmentTimescaledCV = 247,
    pjAssignmentTimescaledBaseline1Work = 289,
    pjAssignmentTimescaledBaseline1Cost = 290,
    pjAssignmentTimescaledBaseline2Work = 298,
    pjAssignmentTimescaledBaseline2Cost = 299,
    pjAssignmentTimescaledBaseline3Work = 307,
    pjAssignmentTimescaledBaseline3Cost = 308,
    pjAssignmentTimescaledBaseline4Work = 316,
    pjAssignmentTimescaledBaseline4Cost = 317,
    pjAssignmentTimescaledBaseline5Work = 325,
    pjAssignmentTimescaledBaseline5Cost = 326,
    pjAssignmentTimescaledBaseline6Work = 334,
    pjAssignmentTimescaledBaseline6Cost = 335,
    pjAssignmentTimescaledBaseline7Work = 343,
    pjAssignmentTimescaledBaseline7Cost = 344,
    pjAssignmentTimescaledBaseline8Work = 352,
    pjAssignmentTimescaledBaseline8Cost = 353,
    pjAssignmentTimescaledBaseline9Work = 361,
    pjAssignmentTimescaledBaseline9Cost = 362,
    pjAssignmentTimescaledBaseline10Work = 370,
    pjAssignmentTimescaledBaseline10Cost = 371,
    pjAssignmentTimescaledActualWorkProtected = 630,
    pjAssignmentTimescaledActualOvertimeWorkProtected = 631,
    pjAssignmentTimescaledBudgetWork = 669,
    pjAssignmentTimescaledBudgetCost = 670,
    pjAssignmentTimescaledBaselineBudgetWork = 673,
    pjAssignmentTimescaledBaselineBudgetCost = 674,
    pjAssignmentTimescaledBaseline1BudgetWork = 677,
    pjAssignmentTimescaledBaseline1BudgetCost = 678,
    pjAssignmentTimescaledBaseline2BudgetWork = 681,
    pjAssignmentTimescaledBaseline2BudgetCost = 682,
    pjAssignmentTimescaledBaseline3BudgetWork = 685,
    pjAssignmentTimescaledBaseline3BudgetCost = 686,
    pjAssignmentTimescaledBaseline4BudgetWork = 689,
    pjAssignmentTimescaledBaseline4BudgetCost = 690,
    pjAssignmentTimescaledBaseline5BudgetWork = 693,
    pjAssignmentTimescaledBaseline5BudgetCost = 694,
    pjAssignmentTimescaledBaseline6BudgetWork = 697,
    pjAssignmentTimescaledBaseline6BudgetCost = 698,
    pjAssignmentTimescaledBaseline7BudgetWork = 701,
    pjAssignmentTimescaledBaseline7BudgetCost = 702,
    pjAssignmentTimescaledBaseline8BudgetWork = 705,
    pjAssignmentTimescaledBaseline8BudgetCost = 706,
    pjAssignmentTimescaledBaseline9BudgetWork = 709,
    pjAssignmentTimescaledBaseline9BudgetCost = 710,
    pjAssignmentTimescaledBaseline10BudgetWork = 713,
    pjAssignmentTimescaledBaseline10BudgetCost = 714,
    pjAssignmentTimescaledCumulativeActualWork = 727,
    pjAssignmentTimescaledRemainingCumulativeActualWork = 728,
    pjAssignmentTimescaledRemainingCumulativeWork = 729,
    pjAssignmentTimescaledBaselineRemainingCumulativeWork = 730,
    pjAssignmentTimescaledBaseline1RemainingCumulativeWork = 731,
    pjAssignmentTimescaledBaseline2RemainingCumulativeWork = 732,
    pjAssignmentTimescaledBaseline3RemainingCumulativeWork = 733,
    pjAssignmentTimescaledBaseline4RemainingCumulativeWork = 734,
    pjAssignmentTimescaledBaseline5RemainingCumulativeWork = 735,
    pjAssignmentTimescaledBaseline6RemainingCumulativeWork = 736,
    pjAssignmentTimescaledBaseline7RemainingCumulativeWork = 737,
    pjAssignmentTimescaledBaseline8RemainingCumulativeWork = 738,
    pjAssignmentTimescaledBaseline9RemainingCumulativeWork = 739,
    pjAssignmentTimescaledBaseline10RemainingCumulativeWork = 740,
    pjAssignmentTimescaledBaselineCumulativeWork = 752,
    pjAssignmentTimescaledBaseline1CumulativeWork = 753,
    pjAssignmentTimescaledBaseline2CumulativeWork = 754,
    pjAssignmentTimescaledBaseline3CumulativeWork = 755,
    pjAssignmentTimescaledBaseline4CumulativeWork = 756,
    pjAssignmentTimescaledBaseline5CumulativeWork = 757,
    pjAssignmentTimescaledBaseline6CumulativeWork = 758,
    pjAssignmentTimescaledBaseline7CumulativeWork = 759,
    pjAssignmentTimescaledBaseline8CumulativeWork = 760,
    pjAssignmentTimescaledBaseline9CumulativeWork = 761,
    pjAssignmentTimescaledBaseline10CumulativeWork = 762
};

enum __declspec(uuid("7a4b6120-923c-11cf-982c-00aa00322803"))
PjToolbarAction
{
    pjToggle = 1,
    pjDelete = 2,
    pjReset = 2,
    pjNew = 3,
    pjCopy = 4,
    pjRename = 5,
    pjShow = 6,
    pjHide = 7
};

enum __declspec(uuid("c1cc3430-923c-11cf-982c-00aa00322803"))
PjUnit
{
    pjMinute = 3,
    pjHour = 5,
    pjDay = 7,
    pjWeek = 9,
    pjMonthUnit = 11
};

enum __declspec(uuid("f0985230-923c-11cf-982c-00aa00322803"))
PjWeekday
{
    pjSunday = 1,
    pjMonday = 2,
    pjTuesday = 3,
    pjWednesday = 4,
    pjThursday = 5,
    pjFriday = 6,
    pjSaturday = 7
};

enum __declspec(uuid("3b76fb00-923d-11cf-982c-00aa00322803"))
PjWeekLabel
{
    pjWeekLabelWeek_mm_dd = 17,
    pjWeekLabelWeek_mm_dd_yy = 16,
    pjWeekLabelWeek_m_dd = 89,
    pjWeekLabelWeek_mmm_dd = 15,
    pjWeekLabelWeek_mmm_dd_yyy = 13,
    pjWeekLabelWeek_mmmm_dd = 14,
    pjWeekLabelWeek_mmmm_dd_yyyy = 12,
    pjWeekLabelWeek_di_mm_dd = 92,
    pjWeekLabelWeek_di_m_dd = 99,
    pjWeekLabelWeek_di_mmm_dd = 95,
    pjWeekLabelWeek_ddi_mm_dd = 91,
    pjWeekLabelWeek_ddi_m_dd = 98,
    pjWeekLabelWeek_ddi_mmm_dd = 94,
    pjWeekLabelWeek_ddd_mm_dd = 90,
    pjWeekLabelWeek_ddd_mm_dd_yy = 100,
    pjWeekLabelWeek_ddd_dd = 88,
    pjWeekLabelWeek_ddd_ww = 103,
    pjWeekLabelWeek_ddd_m_dd = 97,
    pjWeekLabelWeek_ddd_mmm_dd = 93,
    pjWeekLabelWeek_ddd_mmm_dd_yyy = 101,
    pjWeekLabelWeek_ddd_mmmm_dd = 96,
    pjWeekLabelWeek_ddd_mmmm_dd_yyy = 102,
    pjWeekLabelWeekDayOfMonth_dd = 87,
    pjWeekLabelWeekFromEnd_ww = 68,
    pjWeekLabelWeekFromEnd_Www = 67,
    pjWeekLabelWeekFromEnd_Week_ww = 43,
    pjWeekLabelWeekFromStart_ww = 70,
    pjWeekLabelWeekFromStart_Www = 69,
    pjWeekLabelWeekFromStart_Week_ww = 42,
    pjWeekLabelWeekNumber_dd_ww = 104,
    pjWeekLabelWeekNumber_ww = 50,
    pjWeekLabelNoDateFormat = 35
};

enum __declspec(uuid("1dac7bb0-923e-11cf-982c-00aa00322803"))
PjWindowState
{
    pjNormal = 1,
    pjMinimized = 2,
    pjMaximized = 3
};

enum __declspec(uuid("1d2007f0-923f-11cf-982c-00aa00322803"))
PjResourceGraphPattern
{
    pjHollow = 0,
    pjSolidFill = 1,
    pjLightFill = 2,
    pjMediumFill = 3,
    pjDarkFill = 4,
    pjDiagonalLeft = 5,
    pjDiagonalRight = 6,
    pjDiagonalCross = 7,
    pjLineVertical = 8,
    pjLineHorizontal = 9,
    pjLineCross = 10,
    pjNoGraphLine = 0,
    pjGraphContinuous = 1,
    pjGraphDash = 2,
    pjGraphDot = 3,
    pjDashDot = 4,
    pjDashDotDot = 5
};

enum __declspec(uuid("96fb1810-9246-11cf-982c-00aa00322803"))
PjLineType
{
    pjNoLines = 0,
    pjDash = 4,
    pjCloseDot = 2,
    pjDot = 3,
    pjContinuous = 1
};

enum __declspec(uuid("ac8ac400-9628-11cf-982d-00aa00322803"))
PjPasteSpecialType
{
    pjEmbedObject = 0,
    pjPicture = 1,
    pjTextData = 2,
    pjProjectData = 3,
    pjHTMLData = 4,
    pjUnformattedHTMLData = 5
};

enum __declspec(uuid("ee3d5840-bd84-11cf-b4c6-00a0c905437f"))
PjFieldType
{
    pjTask = 0,
    pjResource = 1,
    pjProject = 2
};

enum __declspec(uuid("02b721b0-0b9a-11d0-8c43-00a0c904dcd4"))
PjEnableCancelKey
{
    pjDisabled = 0,
    pjInterrupt = 1,
    pjErrorHandler = 2
};

enum __declspec(uuid("bfd5e850-176c-11d0-b6d2-00a0c904de5c"))
PjPhoneticType
{
    pjKatakanaHalf = 0,
    pjKatakana = 1,
    pjHiragana = 2
};

enum __declspec(uuid("e53af870-1e1e-11d0-b6d2-00a0c904de5c"))
PjAssignmentUnits
{
    pjPercentageAssignmentUnits = 0,
    pjDecimalAssignmentUnits = 1
};

enum __declspec(uuid("db4765b0-2c5b-11d0-8ff5-00a0c903aacf"))
PjPoolOpen
{
    pjPromptPool = 0,
    pjPoolReadOnly = 1,
    pjPoolReadWrite = 2,
    pjPoolAndSharers = 3,
    pjDoNotOpenPool = 4
};

enum __declspec(uuid("ae11a770-3e89-11d0-894e-00a0c90542d1"))
PjOldConstants
{
    pjUsageMinorTimescale = 7,
    pjUsageMajorTimescale = 6,
    pjMenuBars = 6,
    pjGeneralTab = 0,
    pjPredecessorsTab = 1,
    pjResourcesTab = 2,
    pjAdvancedTab = 3,
    pjNotesTab = 4,
    pjUsageProjectStart = -1,
    pjUsageProjectFinish = -1,
    pjUsageMajorColumns = 4,
    pjUsageMinorColumns = 4,
    pjMacMail = 4,
    pjSubscriber = 9,
    pjMPX4 = 12,
    pjPERT = 2,
    pjTaskPERT = 3
};

enum __declspec(uuid("41d661c0-4405-11d0-b721-00aa0057b039"))
PjCopyPictureFor
{
    pjScreen = 0,
    pjPrinter = 1,
    pjGIF = 2
};

enum __declspec(uuid("825576e0-4944-11d0-a53b-00a0c904de55"))
PjIMEMode
{
    pjIMEModeNoControl = 0,
    pjIMEModeOn = 1,
    pjIMEModeOff = 2,
    pjIMEModeDisable = 3,
    pjIMEModeHiragana = 4,
    pjIMEModeKatakana = 5,
    pjIMEModeKatakanaHalf = 6,
    pjIMEModeAlphaFull = 7,
    pjIMEModeAlpha = 8,
    pjIMEModeHangulFull = 9,
    pjIMEModeHangul = 10
};

enum __declspec(uuid("eaf639c0-7551-11d0-8767-00a0c903aacf"))
PjCopyPictureRows
{
    pjCopyOnScreen = 0,
    pjCopySelected = 1
};

enum __declspec(uuid("853fdd10-7aee-11d0-a089-00a0c904dd26"))
PjWorkgroupMessages
{
    pjDefaultMessages = 0,
    pjNoWorkgroupMessages = 1,
    pjWorkgroupViaEmail = 2,
    pjWorkgroupViaWeb = 3,
    pjWorkgroupViaEmailAndWeb = 4
};

enum __declspec(uuid("93152b70-7f02-11d0-930b-00a0c9044f54"))
PjImportMethods
{
    pjImportNew = 0,
    pjImportAppend = 1,
    pjImportMerge = 2
};

enum __declspec(uuid("b1ce2d80-7f02-11d0-930b-00a0c9044f54"))
PjTextFileOrigin
{
    pjTextOriginWin = 0,
    pjTextOriginDOS = 1,
    pjTextOriginMac = 2,
    pjTextOriginUnicode = 3
};

enum __declspec(uuid("7e3a33d0-7f03-11d0-930b-00a0c9044f54"))
PjDataCategories
{
    pjMapTasks = 0,
    pjMapResources = 1,
    pjMapAssignments = 2
};

enum __declspec(uuid("24812930-860e-11d0-b6dc-00a0c904de5c"))
PjTeamStatusCompletedWork
{
    pjTotalForEntirePeriod = 0,
    pjBrokenDownByDay = 1,
    pjBrokenDownByWeek = 2
};

enum __declspec(uuid("9d8a02a0-3ddd-11d2-ae4f-00c04fb6f701"))
PjMSApplication
{
    pjMicrosoftWord = 0,
    pjMicrosoftPowerPoint = 1,
    pjMicrosoftMail = 2,
    pjMicrosoftAccess = 3,
    pjMicrosoftFoxPro = 4,
    pjMicrosoftExcel = 5,
    pjMicrosoftSchedulePlus = 6,
    pjMicrosoftPublisher = 7
};

enum __declspec(uuid("48479c48-5337-11d2-ae57-00c04fb6f701"))
PjWBSSequence
{
    pjWBSOrderedNumbers = 0,
    pjWBSOrderedUppercaseLetters = 1,
    pjWBSOrderedLowercaseLetters = 2,
    pjWBSUnorderedCharacters = 3
};

enum __declspec(uuid("e3cda0c6-5338-11d2-ae57-00c04fb6f701"))
PjCustomOutlineCodeSequence
{
    pjCustomOutlineCodeNumbers = 0,
    pjCustomOutlineCodeUppercaseLetters = 1,
    pjCustomOutlineCodeLowercaseLetters = 2,
    pjCustomOutlineCodeCharacters = 3
};

enum __declspec(uuid("0228af86-6e03-11d2-820f-00c04fb6f3db"))
PjResourceTypes
{
    pjResourceTypeWork = 0,
    pjResourceTypeMaterial = 1,
    pjResourceTypeCost = 2
};

enum __declspec(uuid("df94f1e6-93eb-11d2-89c5-00c04f68fe38"))
PjBoxStyle
{
    pjBoxCritical = 0,
    pjBoxNoncritical = 1,
    pjBoxCriticalMilestone = 2,
    pjBoxNoncriticalMilestone = 3,
    pjBoxCriticalSummary = 4,
    pjBoxNoncriticalSummary = 5,
    pjBoxCriticalInsertedProject = 6,
    pjBoxNoncriticalInsertedProject = 7,
    pjBoxCriticalMarked = 8,
    pjBoxNoncriticalMarked = 9,
    pjBoxCriticalExternalTask = 10,
    pjBoxNoncriticalExternalTask = 11,
    pjBoxProjectSummaryTask = 12,
    pjBoxHighlightedTasks = 13
};

enum __declspec(uuid("7dd2a54c-93ec-11d2-89c5-00c04f68fe38"))
PjBoxShape
{
    pjBoxRectangle = 0,
    pjBoxWideRectangle = 1,
    pjBoxRoundedRectangle = 2,
    pjBoxWideRoundedRectangle = 3,
    pjBoxCapsule = 4,
    pjBoxPointedEnds = 5,
    pjBoxRightParallelogram = 6,
    pjBoxLeftParallelogram = 7,
    pjBoxUpTrapezoid = 8,
    pjBoxDownTrapezoid = 9
};

enum __declspec(uuid("b6aebed8-a5c0-11d2-8bfc-00c04f72f323"))
PjDataTemplate
{
    pjDataTemplateNew = 0,
    pjDataTemplateCopy = 1,
    pjDataTemplateRename = 2,
    pjDataTemplateDelete = 3
};

enum __declspec(uuid("c6cbe2cc-a5c1-11d2-8bfc-00c04f72f323"))
PjCell
{
    pjCell1_1 = 0,
    pjCell2_1 = 1,
    pjCell3_1 = 2,
    pjCell4_1 = 3,
    pjCell1_2 = 4,
    pjCell2_2 = 5,
    pjCell3_2 = 6,
    pjCell4_2 = 7,
    pjCell1_3 = 8,
    pjCell2_3 = 9,
    pjCell3_3 = 10,
    pjCell4_3 = 11,
    pjCell1_4 = 12,
    pjCell2_4 = 13,
    pjCell3_4 = 14,
    pjCell4_4 = 15
};

enum __declspec(uuid("cd570e84-241d-11d3-8c21-00c04f72f323"))
PjBoxSet
{
    pjBoxAddToSelection = 0,
    pjBoxCreate = 1,
    pjBoxMoveAbsolute = 2,
    pjBoxMoveRelative = 3,
    pjBoxSelect = 4,
    pjBoxUnselect = 5
};

enum __declspec(uuid("9da0ecba-9795-11d2-87e2-00c04f72f062"))
PjGroupOn
{
    pjGroupOnEachValue = 0,
    pjGroupOnInterval = 1,
    pjGroupOnDateEachValue = 10,
    pjGroupOnDateMinute = 11,
    pjGroupOnDateHour = 12,
    pjGroupOnDateDay = 13,
    pjGroupOnDateWeek = 14,
    pjGroupOnDateThirdOfMonth = 15,
    pjGroupOnDateMonth = 16,
    pjGroupOnDateQtr = 17,
    pjGroupOnDateYear = 18,
    pjGroupOnDurationEachValue = 20,
    pjGroupOnDurationMinutes = 21,
    pjGroupOnDurationHours = 22,
    pjGroupOnDurationDays = 23,
    pjGroupOnDurationWeeks = 24,
    pjGroupOnDurationMonths = 25,
    pjGroupOnOutlineEachValue = 30,
    pjGroupOnOutlineLevel = 31,
    pjGroupOnPctEachValue = 40,
    pjGroupOnPctInterval = 41,
    pjGroupOnPct1_99 = 42,
    pjGroupOnPct1_50 = 43,
    pjGroupOnPct1_25 = 44,
    pjGroupOnPct1_10 = 45,
    pjGroupOnTextEachValue = 50,
    pjGroupOnTextPrefix = 51
};

enum __declspec(uuid("5d725c6a-a40f-11d2-bc24-00c04fb90759"))
PjAuthentication
{
    pjUserName = 0,
    pjWindowsUserAccount = 1
};

enum __declspec(uuid("33a7eeb0-fe53-11d2-8092-00c04fb90759"))
PjAccountType
{
    pjResourceAccount = 0,
    pjManagerAccount = 1
};

enum __declspec(uuid("6bbba8ac-c5f8-11d2-87ef-00c04f72f062"))
PjBackgroundPattern
{
    pjBackgroundHollow = 0,
    pjBackgroundSolidFill = 1,
    pjBackgroundLightFill = 2,
    pjBackgroundMediumFill = 3,
    pjBackgroundDarkFill = 4,
    pjBackgroundDiagonalLeft = 5,
    pjBackgroundDiagonalRight = 6,
    pjBackgroundDarkDiagonalLeft = 7,
    pjBackgroundDarkDiagonalRight = 8,
    pjBackgroundThinVerticalStripe = 9,
    pjBackgroundMediumVerticalStripe = 10,
    pjBackgroundLightDither = 11,
    pjBackgroundMediumDither = 12,
    pjBackgroundDarkDither = 13
};

enum __declspec(uuid("d194a936-dca4-11d2-ba0c-00c04f72f325"))
PjAutomaticSaveOptions
{
    pjAutomaticSaveActiveProjectOnly = 1,
    pjAutomaticSaveAllOpenProjectFiles = 2
};

enum __declspec(uuid("46aa4dbc-f42d-11d2-a186-00c04f68fe05"))
PJTaskOutlineShowLevel
{
    pjTaskOutlineShowLevel1 = 1,
    pjTaskOutlineShowLevel2 = 2,
    pjTaskOutlineShowLevel3 = 3,
    pjTaskOutlineShowLevel4 = 4,
    pjTaskOutlineShowLevel5 = 5,
    pjTaskOutlineShowLevel6 = 6,
    pjTaskOutlineShowLevel7 = 7,
    pjTaskOutlineShowLevel8 = 8,
    pjTaskOutlineShowLevel9 = 9,
    pjTaskOutlineShowLevelMax = 65535
};

enum __declspec(uuid("4b13ade0-0c0f-11d3-89da-00c04f68fe38"))
PjLayoutMode
{
    pjLayoutAutomatic = 1,
    pjLayoutManual = 2
};

enum __declspec(uuid("c0aacc0e-0c0b-11d3-89da-00c04f68fe38"))
PjLayoutScheme
{
    pjLayoutTopDownFromLeft = 0,
    pjLayoutTopDownByDay = 1,
    pjLayoutTopDownByWeek = 2,
    pjLayoutTopDownByMonth = 3,
    pjLayoutTopDownCriticalFirst = 4,
    pjLayoutCenteredFromLeft = 5,
    pjLayoutCenteredFromTop = 6
};

enum __declspec(uuid("884629fe-0c0f-11d3-89da-00c04f68fe38"))
PjRowColSize
{
    pjSizeBestFit = 0,
    pjSizeFixed = 1
};

enum __declspec(uuid("b30e72c4-0c1c-11d3-89da-00c04f68fe38"))
PjLinkStyle
{
    pjLinkStraight = 1,
    pjLinkRectilinear = 2
};

enum __declspec(uuid("b19a83ec-0c1c-11d3-89da-00c04f68fe38"))
PjLinkColorMode
{
    pjColorModeCustom = 1,
    pjColorModePredecessor = 2
};

enum __declspec(uuid("77500386-0f52-11d3-89da-00c04f68fe38"))
PjAlign
{
    pjAlignLefts = 0,
    pjAlignCenters = 1,
    pjAlignRights = 2,
    pjAlignTops = 3,
    pjAlignMiddles = 4,
    pjAlignBottoms = 5
};

enum __declspec(uuid("d15c9c0f-1f5b-11d3-affe-00c04f68fe88"))
PjCopyPictureScaleOption
{
    pjCopyPictureShowOptions = 0,
    pjCopyPictureKeepRange = 1,
    pjCopyPictureScale = 2,
    pjCopyPictureScaleWRatio = 3,
    pjCopyPictureTimescale = 4,
    pjCopyPictureTruncate = 5
};

enum __declspec(uuid("ecc91e46-2289-11d3-8389-00c04f72f062"))
PjPaperSize
{
    pjPaper10x14 = 16,
    pjPaper11x17 = 17,
    pjPaperA3 = 8,
    pjPaperA4 = 9,
    pjPaperA4Small = 10,
    pjPaperA5 = 11,
    pjPaperB4 = 12,
    pjPaperB5 = 13,
    pjPaperCsheet = 24,
    pjPaperDsheet = 25,
    pjPaperEnvelop10 = 20,
    pjPaperEnvelope11 = 21,
    pjPaperEnvelope12 = 22,
    pjPaperEnvelope14 = 23,
    pjPaperEnvelope9 = 19,
    pjPaperEnvelopeB4 = 33,
    pjPaperEnvelopeB5 = 34,
    pjPaperEnvelopB6 = 35,
    pjPaperEnvelopeC3 = 29,
    pjPaperEnvelopeC4 = 30,
    pjPaperEnvelopeC5 = 28,
    pjPaperEnvelopeC6 = 31,
    pjPaperEnvelopeC65 = 32,
    pjPaperEnvelopeDL = 27,
    pjPaperEnvelopeItaly = 36,
    pjPaperEnvelopeMonarch = 37,
    pjPaperEnvelopePersonal = 38,
    pjPaperEsheet = 26,
    pjPaperExecutive = 7,
    pjPaperFanfoldLegalGerman = 41,
    pjPaperFanfoldStdGerman = 40,
    pjPaperFanfoldUS = 39,
    pjPaperFolio = 14,
    pjPaperLedger = 4,
    pjPaperLegal = 5,
    pjPaperLetter = 1,
    pjPaperLetterSmall = 2,
    pjPaperNote = 18,
    pjPaperQuarto = 15,
    pjPaperStatement = 6,
    pjPaperTabloid = 3,
    pjPaperUser = 255,
    pjPaperDefault = 0,
    pjPaperISOB4 = 42,
    pjPaperJapanesePostcard = 43,
    pjPaper9X11 = 44,
    pjPaper10X11 = 45,
    pjPaper15x11 = 46,
    pjPaperEnvelopeInvite = 47,
    pjPaperLetterExtra = 50,
    pjPaperLegalExtra = 51,
    pjPaperTabloidExtra = 52,
    pjPaperA4Extra = 53,
    pjPaperLetterTransverse = 54,
    pjPaperA4Transverse = 55,
    pjPaperLetterExtraTransverse = 56,
    pjPaperSuperA = 57,
    pjPaperSuperB = 58,
    pjPaperLetterPlus = 59,
    pjPaperA4Plus = 60,
    pjPaperA5Transverse = 61,
    pjPaperB5Transverse = 62,
    pjPaperA3Extra = 63,
    pjPaperA5Extra = 64,
    pjPaperB5Extra = 65,
    pjPaperA2 = 66,
    pjPaperA3Transverse = 67,
    pjPaperA3ExtraTransverse = 68,
    pjPaperJapaneseDoublePostcard = 69,
    pjPaperA6 = 70,
    pjPaperJapaneseEnvelopeKaku2 = 71,
    pjPaperJapaneseEnvelopeKaku3 = 72,
    pjPaperJapaneseEnvelopeChou3 = 73,
    pjPaperJapaneseEnvelopeChou4 = 74,
    pjPaperLetterRotated = 75,
    pjPaperA3Rotated = 76,
    pjPaperA4Rotated = 77,
    pjPaperA5Rotated = 78,
    pjPaperB4JISRotated = 79,
    pjPaperB5JISRotated = 80,
    pjPaperJapanesePostcardRotated = 81,
    pjPaperDoubleJapanesePostcardRotated = 82,
    pjPaperA6Rotated = 83,
    pjPaperJapaneseEnvelopeKaku2Rotated = 84,
    pjPaperJapaneseEnvelopeKaku3Rotated = 85,
    pjPaperJapaneseEnvelopeChou3Rotated = 86,
    pjPaperJapaneseEnvelopeChou4Rotated = 87,
    pjPaperB6JIS = 88,
    pjPaperB6JISRotated = 89,
    pjPaper12x11 = 90,
    pjPaperJapaneseEnvelopeYou4 = 91,
    pjPaperJapaneseEnvelopeYou4Rotated = 92,
    pjPaperPRC16K = 93,
    pjPaperPRC32K = 94,
    pjPaperPRC32KBig = 95,
    pjPaperPRCEnvelope1 = 96,
    pjPaperPRCEnvelope2 = 97,
    pjPaperPRCEnvelope3 = 98,
    pjPaperPRCEnvelope4 = 99,
    pjPaperPRCEnvelope5 = 100,
    pjPaperPRCEnvelope6 = 101,
    pjPaperPRCEnvelope7 = 102,
    pjPaperPRCEnvelope8 = 103,
    pjPaperPRCEnvelope9 = 104,
    pjPaperPRCEnvelope10 = 105,
    pjPaperPRCEnvelope16K = 106,
    pjPaperPRCEnvelope32K = 107,
    pjPaperPRCEnvelope32KBigRotated = 108,
    pjPaperPRCEnvelope1Rotated = 109,
    pjPaperPRCEnvelope2Rotated = 110,
    pjPaperPRCEnvelope3Rotated = 111,
    pjPaperPRCEnvelope4Rotated = 112,
    pjPaperPRCEnvelope5Rotated = 113,
    pjPaperPRCEnvelope6Rotated = 114,
    pjPaperPRCEnvelope7Rotated = 115,
    pjPaperPRCEnvelope8Rotated = 116,
    pjPaperPRCEnvelope9Rotated = 117,
    pjPaperPRCEnvelope10Rotated = 118
};

struct __declspec(uuid("00020b17-0000-0000-c000-000000000046"))
List : IDispatch
{};

struct __declspec(uuid("00020b18-0000-0000-c000-000000000046"))
Selection : IDispatch
{};

struct __declspec(uuid("00020b19-0000-0000-c000-000000000046"))
Cell : IDispatch
{};

struct __declspec(uuid("00020b04-0000-0000-c000-000000000046"))
Pane : IDispatch
{};

struct __declspec(uuid("00020b02-0000-0000-c000-000000000046"))
Window : IDispatch
{};

struct __declspec(uuid("00020b03-0000-0000-c000-000000000046"))
Windows : IDispatch
{};

struct __declspec(uuid("00020b00-0000-0000-c000-000000000046"))
_IProjectDoc : IDispatch
{};

struct __declspec(uuid("f81dd3c0-5089-11cf-a49d-00aa00574c74"))
_EProjectDoc : IDispatch
{};

struct __declspec(uuid("1019a320-508a-11cf-a49d-00aa00574c74"))
Project;
    // [ default ] dispinterface _IProjectDoc
    // [ default, source ] dispinterface _EProjectDoc

struct __declspec(uuid("00020b01-0000-0000-c000-000000000046"))
Projects : IDispatch
{};

struct __declspec(uuid("78e9f620-ebc0-11cf-a523-00a0c904de55"))
_Global : IDispatch
{};

struct __declspec(uuid("00020aff-0000-0000-c000-000000000046"))
_MSProject : IDispatch
{};

struct __declspec(uuid("7b7597d0-0c9f-11d0-8c43-00a0c904dcd4"))
_EProjectApp : IDispatch
{};

struct __declspec(uuid("36d27c48-a1e8-11d3-ba55-00c04f72f325"))
Application;
    // [ default ] dispinterface _MSProject
    // [ source ] dispinterface _EProjectApp
    // [ default, source ] dispinterface _EProjectApp2

struct __declspec(uuid("000c0c50-0000-0000-c000-000000000046"))
Shift : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Start (
        /*[out,retval]*/ VARIANT * pdt ) = 0;
      virtual HRESULT __stdcall put_Start (
        /*[in]*/ VARIANT pdt ) = 0;
      virtual HRESULT __stdcall get_Finish (
        /*[out,retval]*/ VARIANT * pdt ) = 0;
      virtual HRESULT __stdcall put_Finish (
        /*[in]*/ VARIANT pdt ) = 0;
      virtual HRESULT __stdcall Clear ( ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ short * pIndx ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c54-0000-0000-c000-000000000046"))
TimeScaleValue : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_StartDate (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_EndDate (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Clear ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c53-0000-0000-c000-000000000046"))
TimeScaleValues : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct TimeScaleValue * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT Position,
        /*[out,retval]*/ struct TimeScaleValue * * pdisp ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c48-0000-0000-c000-000000000046"))
SplitPart : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * retval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
};

struct __declspec(uuid("000c0c47-0000-0000-c000-000000000046"))
SplitParts : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT StartSplitPartOn,
        /*[in]*/ VARIANT EndSplitPartOn ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * retval ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct SplitPart * * retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * retval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
};

struct __declspec(uuid("7742af30-ebc0-11cf-a523-00a0c904de55"))
Global;
    // [ default ] dispinterface _Global

enum __declspec(uuid("4b7524f4-f3b2-45f9-b8a8-ba2bab84433b"))
PjBaselines
{
    pjBaseline = 0,
    pjBaseline1 = 1,
    pjBaseline2 = 2,
    pjBaseline3 = 3,
    pjBaseline4 = 4,
    pjBaseline5 = 5,
    pjBaseline6 = 6,
    pjBaseline7 = 7,
    pjBaseline8 = 8,
    pjBaseline9 = 9,
    pjBaseline10 = 10
};

enum __declspec(uuid("b69fd2bd-a03b-4ab6-bdda-5baa71a5a372"))
PjStatusType
{
    pjComplete = 0,
    pjOnSchedule = 1,
    pjLate = 2,
    pjFutureTask = 3,
    pjNoData = 4
};

enum __declspec(uuid("827deeff-147d-4ade-a579-758a7270bc1d"))
PjCheckOutType
{
    pjReadOnly = 0,
    pjReadWrite = 1
};

enum __declspec(uuid("de07ed5c-d64c-4230-a1c5-4d365f8d3ce7"))
PjAssignResourcesListFields
{
    pjAllColumns = 2,
    pjBasic = 1
};

enum __declspec(uuid("898735a9-5558-4443-bf1c-ae5f47dbec01"))
PjLoginType
{
    pjWindowsLogin = 1,
    pjProjectServerLogin = 2
};

enum __declspec(uuid("59e971bc-a267-4366-b230-17a336064232"))
PjProfileType
{
    pjLocalProfile = 0,
    pjServerProfile = 1
};

enum __declspec(uuid("c1598a44-9ce0-4a34-a7d0-8c8c0ca707eb"))
PjProfileConnectionState
{
    pjProfileOffline = 0,
    pjProfileOnline = 1
};

enum __declspec(uuid("d8edb415-a2e4-4e1b-8b55-39d246d9eda4"))
PjResourceRequestType
{
    pjResourceRequestTypeNone = 0,
    pjResourceRequestTypeRequest = 1,
    pjResourceRequestTypeDemand = 2
};

enum __declspec(uuid("1616f7e1-0fff-41dc-a6d6-320cbed4a6a0"))
PjEditionType
{
    pjEditionStandard = 0,
    pjEditionProfessional = 1
};

enum __declspec(uuid("a268bb7b-f47a-4aa3-88e0-1b31cbae294c"))
PjResSubstitutionPoolOption
{
    pjResSubstitutionResInProject = 0,
    pjResSubstitutionResInRBS = 1,
    pjResSubstitutionResInList = 2
};

enum __declspec(uuid("b9e30a1d-adbb-494e-8ab4-e4296625d95e"))
PjServerVersionInfo
{
    pjServerVersionInfo_Unknown = -2,
    pjServerVersionInfo_Error = -1,
    pjServerVersionInfo_Email = 0,
    pjServerVersionInfo_P9 = 900,
    pjServerVersionInfo_P10 = 1000,
    pjServerVersionInfo_P11 = 1100,
    pjServerVersionInfo_P12 = 1200,
    pjServerVersionInfo_P14 = 1400
};

enum __declspec(uuid("efe3314b-3460-4231-bfe5-d1e42d807cac"))
PjProjectType
{
    pjProjectTypeUnsaved = 0,
    pjProjectTypeNonEnterprise = 1,
    pjProjectTypeEnterpriseCheckedOut = 2,
    pjProjectTypeEnterpriseReadOnly = 3,
    pjProjectTypeEnterpriseGlobalCheckedOut = 4,
    pjProjectTypeEnterpriseGlobalInMemory = 5,
    pjProjectTypeEnterpriseGlobalLocal = 6,
    pjProjectTypeEnterpriseResourcesCheckedOut = 7,
    pjProjectTypeBasicProjectSite = 8
};

enum __declspec(uuid("c7757769-6fc6-47d6-a5ae-bc11f29daac6"))
PjEarnedValueMethod
{
    pjPercentComplete = 0,
    pjPhysicalPercentComplete = 1
};

enum __declspec(uuid("8e6cc4c6-78f3-4a28-8ad6-2bb04dcefcfe"))
PjSpellingField
{
    pjSpellTaskName = 188743694,
    pjSpellTaskNotes = 188743695,
    pjSpellTaskText1 = 188743731,
    pjSpellTaskText10 = 188743750,
    pjSpellTaskText2 = 188743734,
    pjSpellTaskText3 = 188743737,
    pjSpellTaskText4 = 188743740,
    pjSpellTaskText5 = 188743743,
    pjSpellTaskText6 = 188743746,
    pjSpellTaskText7 = 188743747,
    pjSpellTaskText8 = 188743748,
    pjSpellTaskText9 = 188743749,
    pjSpellTaskText11 = 188743997,
    pjSpellTaskText12 = 188743998,
    pjSpellTaskText13 = 188743999,
    pjSpellTaskText14 = 188744000,
    pjSpellTaskText15 = 188744001,
    pjSpellTaskText16 = 188744002,
    pjSpellTaskText17 = 188744003,
    pjSpellTaskText18 = 188744004,
    pjSpellTaskText19 = 188744005,
    pjSpellTaskText20 = 188744006,
    pjSpellTaskText21 = 188744007,
    pjSpellTaskText22 = 188744008,
    pjSpellTaskText23 = 188744009,
    pjSpellTaskText24 = 188744010,
    pjSpellTaskText25 = 188744011,
    pjSpellTaskText26 = 188744012,
    pjSpellTaskText27 = 188744013,
    pjSpellTaskText28 = 188744014,
    pjSpellTaskText29 = 188744015,
    pjSpellTaskText30 = 188744016,
    pjSpellTaskEnterpriseText1 = 188744479,
    pjSpellTaskEnterpriseText2 = 188744480,
    pjSpellTaskEnterpriseText3 = 188744481,
    pjSpellTaskEnterpriseText4 = 188744482,
    pjSpellTaskEnterpriseText5 = 188744483,
    pjSpellTaskEnterpriseText6 = 188744484,
    pjSpellTaskEnterpriseText7 = 188744485,
    pjSpellTaskEnterpriseText8 = 188744486,
    pjSpellTaskEnterpriseText9 = 188744487,
    pjSpellTaskEnterpriseText10 = 188744488,
    pjSpellTaskEnterpriseText11 = 188744489,
    pjSpellTaskEnterpriseText12 = 188744490,
    pjSpellTaskEnterpriseText13 = 188744491,
    pjSpellTaskEnterpriseText14 = 188744492,
    pjSpellTaskEnterpriseText15 = 188744493,
    pjSpellTaskEnterpriseText16 = 188744494,
    pjSpellTaskEnterpriseText17 = 188744495,
    pjSpellTaskEnterpriseText18 = 188744496,
    pjSpellTaskEnterpriseText19 = 188744497,
    pjSpellTaskEnterpriseText20 = 188744498,
    pjSpellTaskEnterpriseText21 = 188744499,
    pjSpellTaskEnterpriseText22 = 188744500,
    pjSpellTaskEnterpriseText23 = 188744501,
    pjSpellTaskEnterpriseText24 = 188744502,
    pjSpellTaskEnterpriseText25 = 188744503,
    pjSpellTaskEnterpriseText26 = 188744504,
    pjSpellTaskEnterpriseText27 = 188744505,
    pjSpellTaskEnterpriseText28 = 188744506,
    pjSpellTaskEnterpriseText29 = 188744507,
    pjSpellTaskEnterpriseText30 = 188744508,
    pjSpellTaskEnterpriseText31 = 188744509,
    pjSpellTaskEnterpriseText32 = 188744510,
    pjSpellTaskEnterpriseText33 = 188744511,
    pjSpellTaskEnterpriseText34 = 188744512,
    pjSpellTaskEnterpriseText35 = 188744513,
    pjSpellTaskEnterpriseText36 = 188744514,
    pjSpellTaskEnterpriseText37 = 188744515,
    pjSpellTaskEnterpriseText38 = 188744516,
    pjSpellTaskEnterpriseText39 = 188744517,
    pjSpellTaskEnterpriseText40 = 188744518,
    pjSpellProjectEnterpriseText1 = 188744729,
    pjSpellProjectEnterpriseText2 = 188744730,
    pjSpellProjectEnterpriseText3 = 188744731,
    pjSpellProjectEnterpriseText4 = 188744732,
    pjSpellProjectEnterpriseText5 = 188744733,
    pjSpellProjectEnterpriseText6 = 188744734,
    pjSpellProjectEnterpriseText7 = 188744735,
    pjSpellProjectEnterpriseText8 = 188744736,
    pjSpellProjectEnterpriseText9 = 188744737,
    pjSpellProjectEnterpriseText10 = 188744738,
    pjSpellProjectEnterpriseText11 = 188744739,
    pjSpellProjectEnterpriseText12 = 188744740,
    pjSpellProjectEnterpriseText13 = 188744741,
    pjSpellProjectEnterpriseText14 = 188744742,
    pjSpellProjectEnterpriseText15 = 188744743,
    pjSpellProjectEnterpriseText16 = 188744744,
    pjSpellProjectEnterpriseText17 = 188744745,
    pjSpellProjectEnterpriseText18 = 188744746,
    pjSpellProjectEnterpriseText19 = 188744747,
    pjSpellProjectEnterpriseText20 = 188744748,
    pjSpellProjectEnterpriseText21 = 188744749,
    pjSpellProjectEnterpriseText22 = 188744750,
    pjSpellProjectEnterpriseText23 = 188744751,
    pjSpellProjectEnterpriseText24 = 188744752,
    pjSpellProjectEnterpriseText25 = 188744753,
    pjSpellProjectEnterpriseText26 = 188744754,
    pjSpellProjectEnterpriseText27 = 188744755,
    pjSpellProjectEnterpriseText28 = 188744756,
    pjSpellProjectEnterpriseText29 = 188744757,
    pjSpellProjectEnterpriseText30 = 188744758,
    pjSpellProjectEnterpriseText31 = 188744759,
    pjSpellProjectEnterpriseText32 = 188744760,
    pjSpellProjectEnterpriseText33 = 188744761,
    pjSpellProjectEnterpriseText34 = 188744762,
    pjSpellProjectEnterpriseText35 = 188744763,
    pjSpellProjectEnterpriseText36 = 188744764,
    pjSpellProjectEnterpriseText37 = 188744765,
    pjSpellProjectEnterpriseText38 = 188744766,
    pjSpellProjectEnterpriseText39 = 188744767,
    pjSpellProjectEnterpriseText40 = 188744768,
    pjSpellResourceCode = 205520906,
    pjSpellResourceName = 205520897,
    pjSpellResourceNotes = 205520916,
    pjSpellResourceGroup = 205520899,
    pjSpellResourceText1 = 205520904,
    pjSpellResourceText2 = 205520905,
    pjSpellResourceText3 = 205520926,
    pjSpellResourceText4 = 205520927,
    pjSpellResourceText5 = 205520928,
    pjSpellResourceText6 = 205520993,
    pjSpellResourceText7 = 205520994,
    pjSpellResourceText8 = 205520995,
    pjSpellResourceText9 = 205520996,
    pjSpellResourceText10 = 205520997,
    pjSpellResourceText11 = 205521121,
    pjSpellResourceText12 = 205521122,
    pjSpellResourceText13 = 205521123,
    pjSpellResourceText14 = 205521124,
    pjSpellResourceText15 = 205521125,
    pjSpellResourceText16 = 205521126,
    pjSpellResourceText17 = 205521127,
    pjSpellResourceText18 = 205521128,
    pjSpellResourceText19 = 205521129,
    pjSpellResourceText20 = 205521130,
    pjSpellResourceText21 = 205521131,
    pjSpellResourceText22 = 205521132,
    pjSpellResourceText23 = 205521133,
    pjSpellResourceText24 = 205521134,
    pjSpellResourceText25 = 205521135,
    pjSpellResourceText26 = 205521136,
    pjSpellResourceText27 = 205521137,
    pjSpellResourceText28 = 205521138,
    pjSpellResourceText29 = 205521139,
    pjSpellResourceText30 = 205521140,
    pjSpellResourceEnterpriseText1 = 205521542,
    pjSpellResourceEnterpriseText2 = 205521543,
    pjSpellResourceEnterpriseText3 = 205521544,
    pjSpellResourceEnterpriseText4 = 205521545,
    pjSpellResourceEnterpriseText5 = 205521546,
    pjSpellResourceEnterpriseText6 = 205521547,
    pjSpellResourceEnterpriseText7 = 205521548,
    pjSpellResourceEnterpriseText8 = 205521549,
    pjSpellResourceEnterpriseText9 = 205521550,
    pjSpellResourceEnterpriseText10 = 205521551,
    pjSpellResourceEnterpriseText11 = 205521552,
    pjSpellResourceEnterpriseText12 = 205521553,
    pjSpellResourceEnterpriseText13 = 205521554,
    pjSpellResourceEnterpriseText14 = 205521555,
    pjSpellResourceEnterpriseText15 = 205521556,
    pjSpellResourceEnterpriseText16 = 205521557,
    pjSpellResourceEnterpriseText17 = 205521558,
    pjSpellResourceEnterpriseText18 = 205521559,
    pjSpellResourceEnterpriseText19 = 205521560,
    pjSpellResourceEnterpriseText20 = 205521561,
    pjSpellResourceEnterpriseText21 = 205521562,
    pjSpellResourceEnterpriseText22 = 205521563,
    pjSpellResourceEnterpriseText23 = 205521564,
    pjSpellResourceEnterpriseText24 = 205521565,
    pjSpellResourceEnterpriseText25 = 205521566,
    pjSpellResourceEnterpriseText26 = 205521567,
    pjSpellResourceEnterpriseText27 = 205521568,
    pjSpellResourceEnterpriseText28 = 205521569,
    pjSpellResourceEnterpriseText29 = 205521570,
    pjSpellResourceEnterpriseText30 = 205521571,
    pjSpellResourceEnterpriseText31 = 205521572,
    pjSpellResourceEnterpriseText32 = 205521573,
    pjSpellResourceEnterpriseText33 = 205521574,
    pjSpellResourceEnterpriseText34 = 205521575,
    pjSpellResourceEnterpriseText35 = 205521576,
    pjSpellResourceEnterpriseText36 = 205521577,
    pjSpellResourceEnterpriseText37 = 205521578,
    pjSpellResourceEnterpriseText38 = 205521579,
    pjSpellResourceEnterpriseText39 = 205521580,
    pjSpellResourceEnterpriseText40 = 205521581,
    pjSpellAssignmentNotes = 255852615,
    pjSpellAssignmentText1 = 255852632,
    pjSpellAssignmentText2 = 255852633,
    pjSpellAssignmentText3 = 255852634,
    pjSpellAssignmentText4 = 255852635,
    pjSpellAssignmentText5 = 255852636,
    pjSpellAssignmentText6 = 255852637,
    pjSpellAssignmentText7 = 255852638,
    pjSpellAssignmentText8 = 255852639,
    pjSpellAssignmentText9 = 255852640,
    pjSpellAssignmentText10 = 255852641,
    pjSpellAssignmentText11 = 255852762,
    pjSpellAssignmentText12 = 255852763,
    pjSpellAssignmentText13 = 255852764,
    pjSpellAssignmentText14 = 255852765,
    pjSpellAssignmentText15 = 255852766,
    pjSpellAssignmentText16 = 255852767,
    pjSpellAssignmentText17 = 255852768,
    pjSpellAssignmentText18 = 255852769,
    pjSpellAssignmentText19 = 255852770,
    pjSpellAssignmentText20 = 255852771,
    pjSpellAssignmentText21 = 255852772,
    pjSpellAssignmentText22 = 255852773,
    pjSpellAssignmentText23 = 255852774,
    pjSpellAssignmentText24 = 255852775,
    pjSpellAssignmentText25 = 255852776,
    pjSpellAssignmentText26 = 255852777,
    pjSpellAssignmentText27 = 255852778,
    pjSpellAssignmentText28 = 255852779,
    pjSpellAssignmentText29 = 255852780,
    pjSpellAssignmentText30 = 255852781,
    pjSpellAssignmentEnterpriseText1 = 255853045,
    pjSpellAssignmentEnterpriseText2 = 255853046,
    pjSpellAssignmentEnterpriseText3 = 255853047,
    pjSpellAssignmentEnterpriseText4 = 255853048,
    pjSpellAssignmentEnterpriseText5 = 255853049,
    pjSpellAssignmentEnterpriseText6 = 255853050,
    pjSpellAssignmentEnterpriseText7 = 255853051,
    pjSpellAssignmentEnterpriseText8 = 255853052,
    pjSpellAssignmentEnterpriseText9 = 255853053,
    pjSpellAssignmentEnterpriseText10 = 255853054,
    pjSpellAssignmentEnterpriseText11 = 255853055,
    pjSpellAssignmentEnterpriseText12 = 255853056,
    pjSpellAssignmentEnterpriseText13 = 255853057,
    pjSpellAssignmentEnterpriseText14 = 255853058,
    pjSpellAssignmentEnterpriseText15 = 255853059,
    pjSpellAssignmentEnterpriseText16 = 255853060,
    pjSpellAssignmentEnterpriseText17 = 255853061,
    pjSpellAssignmentEnterpriseText18 = 255853062,
    pjSpellAssignmentEnterpriseText19 = 255853063,
    pjSpellAssignmentEnterpriseText20 = 255853064,
    pjSpellAssignmentEnterpriseText21 = 255853065,
    pjSpellAssignmentEnterpriseText22 = 255853066,
    pjSpellAssignmentEnterpriseText23 = 255853067,
    pjSpellAssignmentEnterpriseText24 = 255853068,
    pjSpellAssignmentEnterpriseText25 = 255853069,
    pjSpellAssignmentEnterpriseText26 = 255853070,
    pjSpellAssignmentEnterpriseText27 = 255853071,
    pjSpellAssignmentEnterpriseText28 = 255853072,
    pjSpellAssignmentEnterpriseText29 = 255853073,
    pjSpellAssignmentEnterpriseText30 = 255853074,
    pjSpellAssignmentEnterpriseText31 = 255853075,
    pjSpellAssignmentEnterpriseText32 = 255853076,
    pjSpellAssignmentEnterpriseText33 = 255853077,
    pjSpellAssignmentEnterpriseText34 = 255853078,
    pjSpellAssignmentEnterpriseText35 = 255853079,
    pjSpellAssignmentEnterpriseText36 = 255853080,
    pjSpellAssignmentEnterpriseText37 = 255853081,
    pjSpellAssignmentEnterpriseText38 = 255853082,
    pjSpellAssignmentEnterpriseText39 = 255853083,
    pjSpellAssignmentEnterpriseText40 = 255853084
};

enum __declspec(uuid("ac4a7e94-53a5-4520-99c1-94bf31aaac61"))
PjItemType
{
    pjTaskItem = 0,
    pjResourceItem = 1,
    pjOtherItem = 2
};

enum __declspec(uuid("027c51fc-773b-45fc-a7df-0fbd6418af9e"))
PjPublishInformationOnSave
{
    pjPublishNoSummary = 0,
    pjPublishSummaryOnly = 1,
    pjPublishSummaryAndPlan = 2
};

enum __declspec(uuid("bfdf0e3e-7d6e-4623-b272-c38b28ac6175"))
PjPublishScope
{
    pjPublishScopeDefault = 0,
    pjPublishScopeAll = 1,
    pjPublishScopeVisible = 2,
    pjPublishScopeSelected = 3
};

enum __declspec(uuid("093c217a-4920-42a7-b71e-a92a268bb2af"))
PjProjectServerTrackingMethod
{
    pjTrackingMethodDefault = 0,
    pjTrackingMethodSpecifyHours = 1,
    pjTrackingMethodPercentComplete = 2,
    pjTrackingMethodTotalAndRemaining = 3
};

struct __declspec(uuid("103ef3dc-9fce-4611-8c8b-f306c8881ca5"))
View : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * Dispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * Dispatch ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum PjItemType * Type ) = 0;
      virtual HRESULT __stdcall get_ShowInMenu (
        /*[out,retval]*/ VARIANT_BOOL * ShowInMenu ) = 0;
      virtual HRESULT __stdcall put_ShowInMenu (
        /*[in]*/ VARIANT_BOOL ShowInMenu ) = 0;
      virtual HRESULT __stdcall Apply ( ) = 0;
      virtual HRESULT __stdcall get_Single (
        /*[out,retval]*/ VARIANT_BOOL * Single ) = 0;
      virtual HRESULT __stdcall get_Screen (
        /*[out,retval]*/ enum PjViewScreen * Screen ) = 0;
};

struct __declspec(uuid("4cf32482-106b-4fff-a1ab-7dd395fb0958"))
Views : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct View * * View ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ VARIANT Source,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct View * * View ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("dc2fddaf-ce01-42dc-bb4f-b3fb3346d5b7"))
Filter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * Dispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * Dispatch ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_FilterType (
        /*[out,retval]*/ enum PjItemType * Type ) = 0;
      virtual HRESULT __stdcall get_ShowInMenu (
        /*[out,retval]*/ VARIANT_BOOL * ShowInMenu ) = 0;
      virtual HRESULT __stdcall put_ShowInMenu (
        /*[in]*/ VARIANT_BOOL ShowInMenu ) = 0;
      virtual HRESULT __stdcall Apply (
        /*[in]*/ VARIANT_BOOL Highlight ) = 0;
      virtual HRESULT __stdcall get_ShowRelatedSummaryRows (
        /*[out,retval]*/ VARIANT_BOOL * ShowRelatedSummaryRows ) = 0;
      virtual HRESULT __stdcall put_ShowRelatedSummaryRows (
        /*[in]*/ VARIANT_BOOL ShowRelatedSummaryRows ) = 0;
};

struct __declspec(uuid("ed989e98-f561-4d58-8f67-5d2e2b920e77"))
Filters : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Filter * * Filter ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ VARIANT Source,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Filter * * Filter ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("02497005-3861-4603-80a4-ff309631dba1"))
EventInfo : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Cancel (
        /*[out,retval]*/ VARIANT_BOOL * Cancel ) = 0;
      virtual HRESULT __stdcall put_Cancel (
        /*[in]*/ VARIANT_BOOL Cancel ) = 0;
};

struct __declspec(uuid("6711f81e-aa55-47ee-aa9f-31b00e709cb6"))
Profile : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Server (
        /*[out,retval]*/ BSTR * Server ) = 0;
      virtual HRESULT __stdcall put_Server (
        /*[in]*/ BSTR Server ) = 0;
      virtual HRESULT __stdcall get_LoginType (
        /*[out,retval]*/ enum PjLoginType * LoginType ) = 0;
      virtual HRESULT __stdcall put_LoginType (
        /*[in]*/ enum PjLoginType LoginType ) = 0;
      virtual HRESULT __stdcall get_UserName (
        /*[out,retval]*/ BSTR * UserName ) = 0;
      virtual HRESULT __stdcall put_UserName (
        /*[in]*/ BSTR UserName ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum PjProfileType * profiletype ) = 0;
      virtual HRESULT __stdcall get_ConnectionState (
        /*[out,retval]*/ enum PjProfileConnectionState * profiletype ) = 0;
      virtual HRESULT __stdcall get_SiteId (
        /*[out,retval]*/ BSTR * SiteId ) = 0;
};

struct __declspec(uuid("08cd6de7-87cd-42ab-bd28-6e2c0170a274"))
Profiles : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR Server,
        /*[in]*/ enum PjLoginType LoginType,
        /*[in]*/ BSTR UserName,
        /*[out,retval]*/ struct Profile * * newpf ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Profile * * pf ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_DefaultProfile (
        /*[out,retval]*/ struct Profile * * pf ) = 0;
      virtual HRESULT __stdcall put_DefaultProfile (
        /*[in]*/ struct Profile * pf ) = 0;
      virtual HRESULT __stdcall get_ActiveProfile (
        /*[out,retval]*/ struct Profile * * pf ) = 0;
};

struct __declspec(uuid("5066d7c4-1ed7-48c4-ace7-299e109d368c"))
_EProjectApp2 : IDispatch
{};

enum __declspec(uuid("c6e1e761-d72b-4828-b27c-c1fc306bdfaa"))
PjBookingTypes
{
    pjBookingTypeCommitted = 0,
    pjBookingTypeProposed = 1
};

enum __declspec(uuid("85b5a397-7c1f-406f-93b3-bf8b9ee784d3"))
PjMeasurementUnits
{
    pjInches = 0,
    pjCentimeters = 1,
    pjDefault = 2
};

struct __declspec(uuid("00020b05-0000-0000-c000-000000000046"))
Windows2 : IDispatch
{};

enum __declspec(uuid("e50e45da-6115-4e69-bfac-0d134f8aa2c2"))
PjCustomFieldType
{
    pjInvalidCustomField = 65535,
    pjCostCustomField = 0,
    pjDateCustomField = 1,
    pjDurationCustomField = 2,
    pjFinishCustomField = 3,
    pjFlagCustomField = 4,
    pjNumberCustomField = 5,
    pjStartCustomField = 6,
    pjTextCustomField = 7
};

enum __declspec(uuid("376d979b-21cb-4699-9d08-e07f87b1085a"))
PjExceptionType
{
    pjDaily = 1,
    pjYearlyMonthDay = 2,
    pjYearlyPositional = 3,
    pjMonthlyMonthDay = 4,
    pjMonthlyPositional = 5,
    pjWeekly = 6,
    pjDayCount = 7
};

enum __declspec(uuid("d7c468f1-1ac4-4549-9710-9519d265b478"))
PjExceptionPosition
{
    pjFirst = 0,
    pjSecond = 1,
    pjThird = 2,
    pjFourth = 3,
    pjLast = 4
};

enum __declspec(uuid("b7cf1f5c-84f3-45d1-ba84-7cc5082cc4ac"))
PjExceptionItem
{
    pjItemSunday = 3,
    pjItemMonday = 4,
    pjItemTuesday = 5,
    pjItemWednesday = 6,
    pjItemThursday = 7,
    pjItemFriday = 8,
    pjItemSaturday = 9
};

enum __declspec(uuid("ca629285-3f8b-44c9-9a57-01172dde50da"))
PjCommitmentTaskLinkType
{
    pjNoLink = 0,
    pjTargetStart = 1,
    pjTargetFinish = 2
};

enum __declspec(uuid("270e5811-cfee-41b5-a07c-349c6898b742"))
PjVisualReportsTab
{
    pjTabAll = 0,
    pjTabTaskTP = 1,
    pjTabResourceTP = 2,
    pjTabAssignmentTP = 3,
    pjTabTaskNTP = 4,
    pjTabResourceNTP = 5,
    pjTabAssignmentNTP = 6
};

enum __declspec(uuid("a698c67e-ad36-446c-bcbe-1f88a5f8ab0b"))
PjVisualReportsTemplateType
{
    pjExcel = 1,
    pjVisioMetric = 2,
    pjVisioUS = 3
};

enum __declspec(uuid("89c57a05-2004-44dc-82c8-8642a7dce3d7"))
PjVisualReportsCubeType
{
    pjTaskTP = 1,
    pjResourceTP = 2,
    pjAssignmentTP = 3,
    pjTaskNTP = 4,
    pjResourceNTP = 5,
    pjAssignmentNTP = 6
};

enum __declspec(uuid("939feee3-c067-460b-b389-451a79cc901e"))
PjVisualReportsDataLevel
{
    pjLevelYears = 0,
    pjLevelQuarters = 1,
    pjLevelMonths = 2,
    pjLevelWeeks = 3,
    pjLevelDays = 4,
    pjLevelAutomatic = 5
};

enum __declspec(uuid("80ac48e6-dcf5-4db9-8b34-18f2dc568241"))
PjCalendarType
{
    pjGregorianCalendar = 1,
    pjHijriCalendar = 6,
    pjThaiCalendar = 7
};

enum __declspec(uuid("67988bd9-2ea8-4fd3-ab6a-676864ee486c"))
PjRecalcDriverType
{
    pjDriverActuals = 1,
    pjDriverLevelingDelay = 2,
    pjDriverConstraint = 4,
    pjDriverPredecessor = 8,
    pjDriverProjectStart = 16,
    pjDriverCalendar = 32,
    pjDriverChildTask = 64,
    pjDriverParentTask = 128,
    pjDriverDeadlineTask = 256
};

enum __declspec(uuid("44dd5008-76e2-4bf0-92d3-e53ca2f57ff0"))
PjIsCommandEnabled
{
    pjCommandEnabled = 0,
    pjCommandDisabled = 1,
    pjCommandUndefined = 2
};

enum __declspec(uuid("32494add-37b3-457a-b0cd-64c12e30777d"))
PjThemeElement
{
    pjThemeElementWPBkgd = 32,
    pjThemeElementWPText = 33,
    pjThemeElementWPTitleBkgdInactive = 35,
    pjThemeElementWPCtlBdr = 40,
    pjThemeElementWPGroupline = 47
};

enum __declspec(uuid("8f1b74d2-963d-45a2-b517-0a79deec91c4"))
PjLegacyFileFormats
{
    pjDoNotLoadLegacyFiles = 0,
    pjPromptBeforeLoadingLegacyFiles = 1,
    pjEnableLegacyFilesLoad = 2
};

struct __declspec(uuid("46bff766-f07a-409c-a85f-eed0a36589f9"))
ReportTemplate : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_TemplatePath (
        /*[out,retval]*/ BSTR * Path ) = 0;
      virtual HRESULT __stdcall get_CubeType (
        /*[out,retval]*/ enum PjVisualReportsCubeType * VisualReportsCubeType ) = 0;
      virtual HRESULT __stdcall get_TemplateType (
        /*[out,retval]*/ enum PjVisualReportsTemplateType * VisualReportsTemplateType ) = 0;
};

struct __declspec(uuid("5918f188-19be-401e-a702-fee268804738"))
ReportTemplates : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct ReportTemplate * * pR ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
};

enum __declspec(uuid("6d23c288-2373-11dc-a40f-68e855d89593"))
PjLevelSelectedOption
{
    pjResolveSelectedTasks = 0,
    pjResolveForResource = 1,
    pjResolveNextAvailableTime = 2,
    pjResolveForSelectedResources = 3
};

enum __declspec(uuid("49ceefdd-1a33-4b44-82af-632a29e708ff"))
PjTimelineShowHide
{
    pjTimelineShowHideTaskOverlaps = 0,
    pjTimelineShowHidePanZoom = 1,
    pjTimelineShowHideTimescale = 2,
    pjTimelineShowHideToday = 3,
    pjTimelineShowHideTaskDates = 4
};

enum __declspec(uuid("9e866888-dd3a-44b6-a6e0-54c7c9b06018"))
PjTimelineInsertTaskType
{
    pjTimelineInsertTask = 0,
    pjTimelineInsertMilestone = 1,
    pjTimelineInsertCalloutTask = 2
};

enum __declspec(uuid("3ad17d75-dabd-42d3-bcfe-681a5e8e9543"))
PjNewTasksStartOnDate
{
    pjProjectDate = 0,
    pjCurrentDate = 1,
    pjNoDate = 2
};

enum __declspec(uuid("9e984868-dd3a-44b6-a6e0-54c7c9b06019"))
PjTeamPlannerStyle
{
    pjTPScheduledWork = 0,
    pjTPActualWork = 1,
    pjTPSRA = 2,
    pjTPLateTask = 3,
    pjTPManualTask = 4
};

enum __declspec(uuid("6d54c288-2373-11dc-a40f-68e546e89493"))
PjFieldTypes
{
    pjCostField = 0,
    pjDateField = 1,
    pjDurationField = 2,
    pjFlagField = 3,
    pjFinishField = 4,
    pjNumberField = 5,
    pjStartField = 6,
    pjTextField = 7
};

enum __declspec(uuid("587b6a3e-686a-11dc-89e3-df2b56d89593"))
PjAutoFilterType
{
    pjAutoFilterClear = 0,
    pjAutoFilterCustom = 1,
    pjAutoFilterIn = 2,
    pjAutoFilterToday = 3,
    pjAutoFilterTomorrow = 4,
    pjAutoFilterYesterday = 5,
    pjAutoFilterNextWeek = 6,
    pjAutoFilterThisWeek = 7,
    pjAutoFilterLastWeek = 8,
    pjAutoFilterNextMonth = 9,
    pjAutoFilterThisMonth = 10,
    pjAutoFilterLastMonth = 11,
    pjAutoFilterNextQuarter = 12,
    pjAutoFilterThisQuarter = 13,
    pjAutoFilterLastQuarter = 14,
    pjAutoFilterNextYear = 15,
    pjAutoFilterThisYear = 16,
    pjAutoFilterLastYear = 17,
    pjAutoFilterYearToDate = 18,
    pjAutoFilterBeforeStatusDate = 19,
    pjAutoFilterAfterStatusDate = 20,
    pjAutoFilterNoDate = 21,
    pjAutoFilter1DayOrLess = 22,
    pjAutoFilterBetween1DayAnd1Week = 23,
    pjAutoFilter1WeekOrLonger = 24,
    pjAutoFilterNoDuration = 25,
    pjAutoFilter8HoursOrLess = 26,
    pjAutoFilterBetween8And40Hours = 27,
    pjAutoFilter40HoursOrMore = 28,
    pjAutoFilterNoWork = 29,
    pjAutoFilterNotStarted = 30,
    pjAutoFilterInProgress = 31,
    pjAutoFilterComplete = 32,
    pjAutoFilterWithin1And25Percent = 33,
    pjAutoFilterWithin26And50Percent = 34,
    pjAutoFilterWithin51And75Percent = 35,
    pjAutoFilterWithin76And100Percent = 36,
    pjAutoFilterGreaterThan0Cost = 37,
    pjAutoFilterFlagYes = 38,
    pjAutoFilterFlagNo = 39,
    pjAutoFilterEquals = 40,
    pjAutoFilterNotEquals = 41,
    pjAutoFilterGreaterThan = 42,
    pjAutoFilterLessThan = 43,
    pjAutoFilterBetween = 44,
    pjAutoFilterBeginsWith = 45,
    pjAutoFilterEndsWith = 46,
    pjAutoFilterContains = 47,
    pjAutoFilterNotContains = 48,
    pjAutoFilterPhonetic0 = 49,
    pjAutoFilterPhonetic1 = 50,
    pjAutoFilterPhonetic2 = 51,
    pjAutoFilterPhonetic3 = 52,
    pjAutoFilterPhonetic4 = 53,
    pjAutoFilterPhonetic5 = 54,
    pjAutoFilterPhonetic6 = 55,
    pjAutoFilterPhonetic7 = 56,
    pjAutoFilterPhonetic8 = 57,
    pjAutoFilterPhonetic9 = 58,
    pjAutoFilterPhonetic10 = 59
};

enum __declspec(uuid("587b6a3e-686a-11dc-89e3-ff2b56d89593"))
PjDocExportType
{
    pjPDF = 0,
    pjXPS = 1
};

enum __declspec(uuid("62295145-07f2-4d85-88ad-0572ac317803"))
PjTaskWarnings
{
    pjTaskWarningShadowFinishesLaterDueToLink = 1,
    pjTaskWarningShadowFinishesEarlierDueToLink = 2,
    pjTaskWarningSubTaskStartingBeforeParentStart = 4,
    pjTaskWarningSubTaskStartingAfterParentStart = 8,
    pjTaskWarningSubTaskFinishingAfterParentFinish = 16,
    pjTaskWarningSummaryInconsistentStart = 32,
    pjTaskWarningResourceBeyondMaxUnit = 64,
    pjTaskWarningResourceOverallocated = 128,
    pjTaskWarningShadowIncorrectByConstraintOnly = 256,
    pjTaskWarningShadowIncorrectByLevelingDelayOnly = 512,
    pjTaskWarningShadowDateDifferent = 1024,
    pjTaskWarningSummaryInconsistentFinish = 2048,
    pjTaskWarningTaskStartingInNonWorkingTime = 4096,
    pjTaskWarningTaskFinishingInNonWorkingTime = 8192,
    pjTaskWarningAssnOverallocatedInNonWorkingTime = 16384
};

enum __declspec(uuid("ea16648e-2e49-4ff1-8760-fbcc4f1d1738"))
PjViewType
{
    pjViewUndefined = -1,
    pjViewBarRollup = 0,
    pjViewCalendar = 1,
    pjViewDescriptiveNetworkDiagram = 2,
    pjViewDetailGantt = 3,
    pjViewGantt = 4,
    pjViewGanttWithTimeline = 5,
    pjViewLevelingGantt = 6,
    pjViewMilestoneDateRollup = 7,
    pjViewMilestoneRollup = 8,
    pjViewMultipleBaselinesGantt = 9,
    pjViewNetworkDiagram = 10,
    pjViewRelationshipDiagram = 11,
    pjViewResourceAllocation = 12,
    pjViewResourceForm = 13,
    pjViewResourceGraph = 14,
    pjViewResourceNameForm = 15,
    pjViewResourceSchedulingView = 16,
    pjViewResourceSheet = 17,
    pjViewResourceUsage = 18,
    pjViewTaskForm = 19,
    pjViewTaskDetailsForm = 20,
    pjViewTaskEntry = 21,
    pjViewTaskNameForm = 22,
    pjViewTaskSheet = 23,
    pjViewTaskUsage = 24,
    pjViewTimeline = 25,
    pjViewTrackingGantt = 26
};

enum __declspec(uuid("3c20c201-d063-424d-9c40-2dde6939a324"))
PjCompareVersionItems
{
    pjCompareVersionItemsAllDifferences = 0,
    pjCompareVersionItemsChangedItems = 1,
    pjCompareVersionItemsUnchangedItems = 2,
    pjCompareVersionItemsCommonItems = 3,
    pjCompareVersionItemsUniqueItemsOfVersion1 = 4,
    pjCompareVersionItemsUniqueItemsOfVersion2 = 5,
    pjCompareVersionItemsAllItems = 6
};

enum __declspec(uuid("0e4f5320-c10d-45ed-a34c-78dda6a45b52"))
PjCompareVersionColumns
{
    pjCompareVersionColumnsDataAndDifferences = 0,
    pjCompareVersionColumnsDataOnly = 1,
    pjCompareVersionColumnsDifferencesOnly = 2
};

enum __declspec(uuid("96a31879-912b-40d1-876d-155ff75a217f"))
PjAssignmentReplanAction
{
    pjConstrainToMaxUnitsByIncreasingDuration = 0,
    pjConstrainToMaxUnitsByDecreasingWork = 1
};

enum __declspec(uuid("ddaf0ce6-c804-467d-a119-0b2575398a5a"))
PjOptionsSecurityTab
{
    pjOptionsSecurityTabPublishers = 0,
    pjOptionsSecurityTabAddins = 1,
    pjOptionsSecurityTabMacro = 2,
    pjOptionsSecurityTabPrivacy = 3,
    pjOptionsSecurityTabLegacy = 4
};

enum __declspec(uuid("f403186b-4826-4d76-b51f-21095832461b"))
PjServerPage
{
    pjServerPageApprovals = 0,
    pjServerPageResourceCenter = 1,
    pjServerPageProjectCenter = 2,
    pjServerPagePortfolioAnalyzer = 3,
    pjServerPageStatusReports = 4,
    pjServerPagePermissions = 5,
    pjServerPageProjectDetails = 6,
    pjServerPageDocuments = 7,
    pjServerPageIssues = 8,
    pjServerPageRisks = 9,
    pjServerPageWorkspace = 10
};

enum __declspec(uuid("9ec90a6e-82eb-45c9-a466-9bce80f49a3f"))
PjFilterViewType
{
    pjFilterViewTypeTask = 0,
    pjFilterViewTypeResource = 1,
    pjFilterViewTypeUseView = 65535
};

enum __declspec(uuid("30e93821-a2d8-4f2f-9ef4-328811adfc75"))
PjOverallocationType
{
    pjOverallocationTypeNone = 0,
    pjOverallocationTypeAboveMaxUnits = 1,
    pjOverallocationTypeWorkingInNonWorkingTime = 2,
    pjOverallocationTypeWorkingOnOtherTasks = 3
};

enum __declspec(uuid("5a0b1b07-fa9c-4aa6-8a45-1bf09546c8ba"))
PjReportLayoutTemplateId
{
    pjReportLayoutTitleOnly = 0,
    pjReportLayoutTitleAndChart = 1,
    pjReportLayoutTitleAndTable = 2,
    pjReportLayoutComparison = 3
};

enum __declspec(uuid("218475cf-a0e3-4b28-b3a0-9d003446e108"))
PjCacheJobState
{
    pjCacheJobStateInvalid = -1,
    pjCacheJobStateUnknown = 0,
    pjCacheJobStateReadyForProcessing = 1,
    pjCacheJobStateSendIncomplete = 2,
    pjCacheJobStateProcessing = 3,
    pjCacheJobStateSuccess = 4,
    pjCacheJobStateFailed = 5,
    pjCacheJobStateFailedNotBlocking = 6,
    pjCacheJobStateSkipped = 7,
    pjCacheJobStateCorrelationBlocked = 8,
    pjCacheJobStateCancelled = 9,
    pjCacheJobStateOnHold = 10,
    pjCacheJobStateSleeping = 11,
    pjCacheJobStateReadyForLaunch = 12,
    pjCacheJobStateLastState = 13
};

enum __declspec(uuid("f5f71a8c-dc95-4a9b-9b93-f6e8a415c2b4"))
PjJobType
{
    pjCacheProjectSave = 0,
    pjCacheProjectCheckin = 1,
    pjCacheProjectPublish = 2
};

struct __declspec(uuid("33daa9fa-94ca-414e-bcf4-3e260b02b55e"))
ReportTable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_RowsCount (
        /*[out,retval]*/ int * pRowsCount ) = 0;
      virtual HRESULT __stdcall get_ColumnsCount (
        /*[out,retval]*/ int * pColumnsCount ) = 0;
      virtual HRESULT __stdcall UpdateTableData (
        /*[in]*/ VARIANT_BOOL Task,
        /*[in]*/ BSTR GroupName,
        /*[in]*/ BSTR FilterName,
        /*[in]*/ int OutlineLevel,
        /*[in]*/ VARIANT SafeArrayOfPjField = vtMissing ) = 0;
      virtual HRESULT __stdcall GetCellText (
        /*[in]*/ int Row,
        /*[in]*/ int Col,
        /*[out,retval]*/ BSTR * pCellText ) = 0;
};

struct __declspec(uuid("da4986e8-ff38-4c85-881a-78f79f1436d9"))
Series : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall get_Values (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_XValues (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
};

struct __declspec(uuid("787fbde2-e363-48aa-94e1-fb94474770b7"))
SeriesCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Series * * RHS ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Series * * RHS ) = 0;
};

struct __declspec(uuid("000c0c3f-0000-0000-c000-000000000046"))
Task : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_WorkVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_RemainingWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_CostVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BCWP (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BCWS (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_SV (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Notes (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Notes (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_WBS (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_WBS (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ConstraintType (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ConstraintType (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ConstraintDate (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ConstraintDate (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Critical (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_LevelingDelay (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_LevelingDelay (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_FreeSlack (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_TotalSlack (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_Milestone (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Milestone (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Priority (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Priority (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Subproject (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Subproject (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_BaselineDuration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineDuration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualDuration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualDuration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_DurationVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingDuration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_RemainingDuration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_PercentComplete (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_PercentComplete (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_PercentWorkComplete (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_PercentWorkComplete (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_FixedDuration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_FixedDuration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EarlyStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EarlyFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_LateStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_LateFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ActualStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_StartVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_FinishVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Text1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Start1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Text2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Start2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Text3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Start3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Text4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Start4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Text5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Start5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Text6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Marked (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Marked (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Rollup (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Rollup (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_CV (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Project (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_OutlineLevel (
        /*[out,retval]*/ short * retval ) = 0;
      virtual HRESULT __stdcall get_UniqueID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_Number1 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number1 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number2 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number2 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number3 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number3 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number4 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number4 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number5 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number5 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Summary (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Created (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_UniqueIDPredecessors (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_UniqueIDPredecessors (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_UniqueIDSuccessors (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_UniqueIDSuccessors (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Objects (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_LinkedFields (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Resume (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Resume (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Stop (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Stop (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ResumeNoEarlierThan (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ResumeNoEarlierThan (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_OutlineNumber (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_Duration1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_HideBar (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_HideBar (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Confirmed (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_UpdateNeeded (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Contact (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Contact (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ResourceGroup (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_ACWP (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum PjTaskFixedType * retval ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum PjTaskFixedType retval ) = 0;
      virtual HRESULT __stdcall get_Recurring (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EffortDriven (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EffortDriven (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_OutlineChildren (
        /*[out,retval]*/ struct Tasks * * retval ) = 0;
      virtual HRESULT __stdcall get_PredecessorTasks (
        /*[out,retval]*/ struct Tasks * * retval ) = 0;
      virtual HRESULT __stdcall get_SuccessorTasks (
        /*[out,retval]*/ struct Tasks * * retval ) = 0;
      virtual HRESULT __stdcall get_OvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingOvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RegularWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_OvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingOvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Assignments (
        /*[out,retval]*/ struct Assignments * * retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * retval ) = 0;
      virtual HRESULT __stdcall put_Parent (
        /*[in]*/ IDispatch * retval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall get_Hyperlink (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Hyperlink (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkAddress (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkAddress (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkSubAddress (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkSubAddress (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkHREF (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkHREF (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Overallocated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_SplitParts (
        /*[out,retval]*/ struct SplitParts * * retval ) = 0;
      virtual HRESULT __stdcall GetField (
        /*[in]*/ enum PjField FieldID,
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall SetField (
        /*[in]*/ enum PjField FieldID,
        /*[in]*/ BSTR Value ) = 0;
      virtual HRESULT __stdcall get_ExternalTask (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall AppendNotes (
        /*[in]*/ BSTR Value ) = 0;
      virtual HRESULT __stdcall get_OutlineParent (
        /*[out,retval]*/ struct Task * * retval ) = 0;
      virtual HRESULT __stdcall get_Resources (
        /*[out,retval]*/ struct Resources * * retval ) = 0;
      virtual HRESULT __stdcall TimeScaleData (
        /*[in]*/ VARIANT StartDate,
        /*[in]*/ VARIANT EndDate,
        /*[in]*/ enum PjTaskTimescaledData Type,
        /*[in]*/ enum PjTimescaleUnit TimeScaleUnit,
        /*[in]*/ long Count,
        /*[out,retval]*/ struct TimeScaleValues * * retval ) = 0;
      virtual HRESULT __stdcall get_SubProjectReadOnly (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_SubProjectReadOnly (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ResponsePending (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_TeamStatusPending (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_LevelingCanSplit (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_LevelingCanSplit (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_LevelIndividualAssignments (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_LevelIndividualAssignments (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Number6 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number6 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number7 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number7 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number8 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number8 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number9 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number9 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number10 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number10 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number11 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number11 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number12 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number12 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number13 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number13 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number14 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number14 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number15 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number15 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number16 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number16 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number17 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number17 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number18 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number18 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number19 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number19 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number20 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number20 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Text11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ResourcePhonetics (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall LinkPredecessors (
        /*[in]*/ IDispatch * Tasks,
        /*[in]*/ enum PjTaskLinkType Link,
        /*[in]*/ VARIANT Lag = vtMissing ) = 0;
      virtual HRESULT __stdcall LinkSuccessors (
        /*[in]*/ IDispatch * Tasks,
        /*[in]*/ enum PjTaskLinkType Link,
        /*[in]*/ VARIANT Lag = vtMissing ) = 0;
      virtual HRESULT __stdcall UnlinkPredecessors (
        /*[in]*/ IDispatch * Tasks ) = 0;
      virtual HRESULT __stdcall UnlinkSuccessors (
        /*[in]*/ IDispatch * Tasks ) = 0;
      virtual HRESULT __stdcall OutlineIndent ( ) = 0;
      virtual HRESULT __stdcall OutlineOutdent ( ) = 0;
      virtual HRESULT __stdcall OutlineHideSubTasks ( ) = 0;
      virtual HRESULT __stdcall OutlineShowSubTasks ( ) = 0;
      virtual HRESULT __stdcall OutlineShowAllTasks ( ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_PreleveledStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_PreleveledFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall Split (
        /*[in]*/ VARIANT StartSplitOn,
        /*[in]*/ VARIANT EndSplitOn ) = 0;
      virtual HRESULT __stdcall get_Predecessors (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Predecessors (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Successors (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Successors (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ResourceNames (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_ResourceNames (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ResourceInitials (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_ResourceInitials (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall put_OutlineLevel (
        /*[in]*/ short retval ) = 0;
      virtual HRESULT __stdcall get_Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_IgnoreResourceCalendar (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_IgnoreResourceCalendar (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Calendar (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Calendar (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Duration1Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration1Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration2Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration2Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration3Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration3Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration4Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration4Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration5Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration5Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration6Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration6Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration7Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration7Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration8Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration8Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration9Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration9Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration10Estimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration10Estimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineDurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineDurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Deadline (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Deadline (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_StartSlack (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_FinishSlack (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_VAC (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_TaskDependencies (
        /*[out,retval]*/ struct TaskDependencies * * retval ) = 0;
      virtual HRESULT __stdcall get_GroupBySummary (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_WBSPredecessors (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_WBSSuccessors (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkScreenTip (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkScreenTip (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_CPI (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall get_SPI (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall get_CVPercent (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_SVPercent (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EAC (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_TCPI (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall get_Status (
        /*[out,retval]*/ enum PjStatusType * retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Duration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Duration (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate21 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate21 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate22 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate22 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate23 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate23 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate24 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate24 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate25 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate25 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate26 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate26 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate27 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate27 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate28 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate28 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate29 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate29 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate30 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate30 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber1 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber1 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber2 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber2 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber3 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber3 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber4 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber4 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber5 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber5 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber6 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber6 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber7 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber7 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber8 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber8 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber9 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber9 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber10 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber10 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber11 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber11 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber12 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber12 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber13 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber13 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber14 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber14 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber15 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber15 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber16 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber16 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber17 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber17 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber18 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber18 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber19 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber19 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber20 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber20 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber21 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber21 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber22 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber22 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber23 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber23 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber24 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber24 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber25 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber25 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber26 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber26 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber27 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber27 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber28 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber28 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber29 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber29 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber30 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber30 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber31 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber31 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber32 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber32 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber33 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber33 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber34 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber34 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber35 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber35 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber36 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber36 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber37 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber37 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber38 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber38 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber39 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber39 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber40 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber40 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText31 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText31 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText32 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText32 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText33 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText33 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText34 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText34 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText35 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText35 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText36 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText36 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText37 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText37 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText38 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText38 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText39 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText39 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText40 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText40 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10DurationEstimated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10DurationEstimated (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_PhysicalPercentComplete (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_PhysicalPercentComplete (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EarnedValueMethod (
        /*[out,retval]*/ enum PjEarnedValueMethod * retval ) = 0;
      virtual HRESULT __stdcall put_EarnedValueMethod (
        /*[in]*/ enum PjEarnedValueMethod retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectCost10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectCost10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate21 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate21 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate22 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate22 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate23 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate23 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate24 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate24 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate25 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate25 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate26 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate26 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate27 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate27 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate28 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate28 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate29 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate29 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDate30 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDate30 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectDuration10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectDuration10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectOutlineCode30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectOutlineCode30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectFlag20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectFlag20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber1 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber1 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber2 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber2 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber3 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber3 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber4 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber4 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber5 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber5 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber6 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber6 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber7 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber7 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber8 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber8 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber9 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber9 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber10 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber10 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber11 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber11 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber12 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber12 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber13 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber13 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber14 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber14 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber15 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber15 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber16 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber16 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber17 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber17 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber18 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber18 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber19 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber19 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber20 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber20 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber21 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber21 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber22 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber22 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber23 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber23 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber24 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber24 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber25 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber25 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber26 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber26 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber27 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber27 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber28 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber28 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber29 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber29 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber30 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber30 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber31 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber31 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber32 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber32 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber33 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber33 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber34 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber34 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber35 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber35 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber36 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber36 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber37 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber37 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber38 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber38 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber39 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber39 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectNumber40 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectNumber40 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText31 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText31 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText32 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText32 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText33 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText33 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText34 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText34 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText35 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText35 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText36 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText36 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText37 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText37 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText38 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText38 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText39 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText39 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseProjectText40 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseProjectText40 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ActualWorkProtected (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualWorkProtected (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvertimeWorkProtected (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualOvertimeWorkProtected (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineFixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineFixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10FixedCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10FixedCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Guid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_CalendarGuid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_DeliverableGuid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_DeliverableGuid (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_DeliverableType (
        /*[out,retval]*/ short * retval ) = 0;
      virtual HRESULT __stdcall put_DeliverableType (
        /*[in]*/ short retval ) = 0;
      virtual HRESULT __stdcall get_DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_IsPublished (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_IsPublished (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_StatusManagerName (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_StatusManagerName (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ErrorMessage (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineFixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineFixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_BaselineDeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineDeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineDeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineDeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineBudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineBudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineBudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineBudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10FixedCostAccrual (
        /*[out,retval]*/ enum PjAccrueAt * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10FixedCostAccrual (
        /*[in]*/ enum PjAccrueAt retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10DeliverableStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10DeliverableStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10DeliverableFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10DeliverableFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_RecalcFlags (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_StartDriver (
        /*[out,retval]*/ struct StartDriver * * retval ) = 0;
      virtual HRESULT __stdcall get_DeliverableName (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_DeliverableName (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Active (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Active (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Manual (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Manual (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Placeholder (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Warning (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_IsStartValid (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_IsFinishValid (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_IsDurationValid (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BaselineStartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineStartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_BaselineFinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineFinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_BaselineDurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineDurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10StartText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10StartText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10FinishText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10FinishText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10DurationText (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10DurationText (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_IgnoreWarnings (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_IgnoreWarnings (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_CalendarObject (
        /*[out,retval]*/ struct Calendar * * retval ) = 0;
      virtual HRESULT __stdcall get_ScheduledStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ScheduledFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ScheduledDuration (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_PathDrivingPredecessor (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_PathPredecessor (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_PathDrivenSuccessor (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_PathSuccessor (
        /*[out,retval]*/ VARIANT * retval ) = 0;
};

struct __declspec(uuid("00020b1c-0000-0000-c000-000000000046"))
Subproject : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_LinkToSource (
        /*[out,retval]*/ VARIANT_BOOL * fLinkToSource ) = 0;
      virtual HRESULT __stdcall put_LinkToSource (
        /*[in]*/ VARIANT_BOOL fLinkToSource ) = 0;
      virtual HRESULT __stdcall get_Path (
        /*[out,retval]*/ BSTR * szPath ) = 0;
      virtual HRESULT __stdcall put_Path (
        /*[in]*/ BSTR szPath ) = 0;
      virtual HRESULT __stdcall get_ReadOnly (
        /*[out,retval]*/ VARIANT_BOOL * fReadOnly ) = 0;
      virtual HRESULT __stdcall put_ReadOnly (
        /*[in]*/ VARIANT_BOOL fReadOnly ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_SourceProject (
        /*[out,retval]*/ struct _IProjectDoc * * ppProject ) = 0;
      virtual HRESULT __stdcall get_InsertedProjectSummary (
        /*[out,retval]*/ struct Task * * ppTask ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * lIndex ) = 0;
      virtual HRESULT __stdcall get_IsLoaded (
        /*[out,retval]*/ VARIANT_BOOL * pfLoaded ) = 0;
};

struct __declspec(uuid("00020b1b-0000-0000-c000-000000000046"))
Subprojects : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Subproject * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
};

struct __declspec(uuid("a7c6acb0-58c6-11d2-ae5a-00c04fb6f701"))
TaskDependency : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_From (
        /*[out,retval]*/ struct Task * * pdisp ) = 0;
      virtual HRESULT __stdcall get_To (
        /*[out,retval]*/ struct Task * * pdisp ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum PjTaskLinkType * retval ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum PjTaskLinkType retval ) = 0;
      virtual HRESULT __stdcall get_Lag (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Lag (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Path (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall put_Path (
        /*[in]*/ VARIANT pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Task * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_LagType (
        /*[out,retval]*/ enum PjFormatUnit * retval ) = 0;
};

struct __declspec(uuid("a7c6acb1-58c6-11d2-ae5a-00c04fb6f701"))
TaskDependencies : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct TaskDependency * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ struct Task * From,
        /*[in]*/ enum PjTaskLinkType Type,
        /*[in]*/ VARIANT Lag,
        /*[out,retval]*/ struct TaskDependency * * pdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Task * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c40-0000-0000-c000-000000000046"))
Tasks : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * retval ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_UniqueID (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct Task * * retval ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Before,
        /*[out,retval]*/ struct Task * * retval ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Task * * retval ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
};

struct __declspec(uuid("9dd14143-f0a9-4692-8288-a6835f93dc8a"))
PredecessorDrivers : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct TaskDependency * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_TotalDetectedCount (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Task * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("9dd14144-f0a9-4692-8288-a6835f93dc8a"))
ChildDrivers : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct Task * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_TotalDetectedCount (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Task * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c41-0000-0000-c000-000000000046"))
Resource : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Initials (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Initials (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Group (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Group (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_MaxUnits (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_MaxUnits (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaseCalendar (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_BaseCalendar (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_StandardRate (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_StandardRate (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_OvertimeRate (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_OvertimeRate (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Text1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Code (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Code (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ActualCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ActualWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BaselineWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_OvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BaselineCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_CostPerUse (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_CostPerUse (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_AccrueAt (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_AccrueAt (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Notes (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Notes (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_RemainingCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_WorkVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_CostVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Overallocated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_PeakUnits (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_UniqueID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_PercentWorkComplete (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Text3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Objects (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_LinkedFields (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EMailAddress (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EMailAddress (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_RegularWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingOvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_OvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingOvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BCWS (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BCWP (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ACWP (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_SV (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Assignments (
        /*[out,retval]*/ struct Assignments * * retval ) = 0;
      virtual HRESULT __stdcall get_AvailableFrom (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_AvailableFrom (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_AvailableTo (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_AvailableTo (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * retval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall get_Text6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Start1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Number1 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number1 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number2 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number2 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number3 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number3 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number4 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number4 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number5 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number5 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Duration1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Hyperlink (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Hyperlink (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkAddress (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkAddress (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkSubAddress (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkSubAddress (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkHREF (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkHREF (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall GetField (
        /*[in]*/ enum PjField FieldID,
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall SetField (
        /*[in]*/ enum PjField FieldID,
        /*[in]*/ BSTR Value ) = 0;
      virtual HRESULT __stdcall get_Calendar (
        /*[out,retval]*/ struct Calendar * * retval ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall AppendNotes (
        /*[in]*/ BSTR Value ) = 0;
      virtual HRESULT __stdcall TimeScaleData (
        /*[in]*/ VARIANT StartDate,
        /*[in]*/ VARIANT EndDate,
        /*[in]*/ enum PjResourceTimescaledData Type,
        /*[in]*/ enum PjTimescaleUnit TimeScaleUnit,
        /*[in]*/ long Count,
        /*[out,retval]*/ struct TimeScaleValues * * retval ) = 0;
      virtual HRESULT __stdcall get_CostRateTables (
        /*[out,retval]*/ struct CostRateTables * * retval ) = 0;
      virtual HRESULT __stdcall get_PayRates (
        /*[out,retval]*/ struct PayRates * * retval ) = 0;
      virtual HRESULT __stdcall get_CanLevel (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_CanLevel (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Number6 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number6 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number7 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number7 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number8 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number8 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number9 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number9 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number10 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number10 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number11 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number11 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number12 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number12 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number13 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number13 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number14 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number14 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number15 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number15 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number16 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number16 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number17 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number17 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number18 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number18 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number19 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number19 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number20 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number20 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Start6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Text11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Phonetics (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Phonetics (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall Level ( ) = 0;
      virtual HRESULT __stdcall get_Confirmed (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ResponsePending (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_TeamStatusPending (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_UpdateNeeded (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_CV (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Workgroup (
        /*[out,retval]*/ enum PjWorkgroupMessages * retval ) = 0;
      virtual HRESULT __stdcall put_Workgroup (
        /*[in]*/ enum PjWorkgroupMessages retval ) = 0;
      virtual HRESULT __stdcall get_Project (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_Availabilities (
        /*[out,retval]*/ struct Availabilities * * retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_OutlineCode10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_OutlineCode10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_MaterialLabel (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_MaterialLabel (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum PjResourceTypes * retval ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum PjResourceTypes retval ) = 0;
      virtual HRESULT __stdcall get_VAC (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_GroupBySummary (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_WindowsUserAccount (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_WindowsUserAccount (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkScreenTip (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkScreenTip (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseUniqueID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate21 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate21 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate22 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate22 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate23 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate23 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate24 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate24 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate25 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate25 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate26 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate26 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate27 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate27 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate28 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate28 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate29 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate29 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate30 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate30 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber1 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber1 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber2 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber2 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber3 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber3 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber4 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber4 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber5 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber5 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber6 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber6 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber7 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber7 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber8 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber8 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber9 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber9 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber10 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber10 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber11 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber11 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber12 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber12 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber13 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber13 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber14 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber14 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber15 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber15 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber16 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber16 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber17 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber17 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber18 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber18 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber19 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber19 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber20 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber20 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber21 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber21 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber22 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber22 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber23 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber23 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber24 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber24 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber25 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber25 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber26 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber26 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber27 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber27 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber28 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber28 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber29 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber29 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber30 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber30 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber31 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber31 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber32 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber32 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber33 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber33 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber34 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber34 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber35 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber35 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber36 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber36 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber37 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber37 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber38 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber38 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber39 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber39 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber40 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber40 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseOutlineCode29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseOutlineCode29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseRBS (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseRBS (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText31 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText31 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText32 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText32 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText33 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText33 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText34 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText34 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText35 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText35 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText36 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText36 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText37 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText37 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText38 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText38 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText39 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText39 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText40 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText40 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseGeneric (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseGeneric (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseBaseCalendar (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseRequiredValues (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNameUsed (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Enterprise (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseIsCheckedOut (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCheckedOutBy (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseLastModifiedDate (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseInactive (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseInactive (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall EnterpriseTeamMember (
        /*[in]*/ IDispatch * Project,
        /*[out,retval]*/ VARIANT_BOOL * retval ) = 0;
      virtual HRESULT __stdcall get_BookingType (
        /*[out,retval]*/ enum PjBookingTypes * retval ) = 0;
      virtual HRESULT __stdcall put_BookingType (
        /*[in]*/ enum PjBookingTypes retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseMultiValue29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseMultiValue29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ActualWorkProtected (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualWorkProtected (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvertimeWorkProtected (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualOvertimeWorkProtected (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Created (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Created (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Guid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_CalendarGuid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_ErrorMessage (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_DefaultAssignmentOwner (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_DefaultAssignmentOwner (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Budget (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Budget (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Import (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Import (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineBudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineBudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineBudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineBudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_IsTeam (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_IsTeam (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_CostCenter (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_CostCenter (
        /*[in]*/ BSTR retval ) = 0;
};

struct __declspec(uuid("000c0c45-0000-0000-c000-000000000046"))
Assignment : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_UniqueID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_TaskUniqueID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall put_TaskUniqueID (
        /*[in]*/ long retval ) = 0;
      virtual HRESULT __stdcall get_ResourceUniqueID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall put_ResourceUniqueID (
        /*[in]*/ long retval ) = 0;
      virtual HRESULT __stdcall get_TaskID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall put_TaskID (
        /*[in]*/ long retval ) = 0;
      virtual HRESULT __stdcall get_ResourceID (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall put_ResourceID (
        /*[in]*/ long retval ) = 0;
      virtual HRESULT __stdcall get_TaskName (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_TaskName (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ResourceName (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_ResourceName (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Units (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Units (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_OvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_OvertimeWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_RegularWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_RegularWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_RemainingWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_RemainingWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualOvertimeWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_RemainingOvertimeWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_RemainingOvertimeWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Peak (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Delay (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Delay (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_OvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ActualCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_RemainingCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_RemainingOvertimeCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BaselineCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BCWS (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_BCWP (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ACWP (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_SV (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_CostVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_WorkContour (
        /*[out,retval]*/ enum PjWorkContourType * retval ) = 0;
      virtual HRESULT __stdcall put_WorkContour (
        /*[in]*/ enum PjWorkContourType retval ) = 0;
      virtual HRESULT __stdcall get_PercentWorkComplete (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_PercentWorkComplete (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Project (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_Notes (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Notes (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Confirmed (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Confirmed (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ResponsePending (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ResponsePending (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_UpdateNeeded (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_TeamStatusPending (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_TeamStatusPending (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_CostRateTable (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_CostRateTable (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * retval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall get_Text1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Start1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Number1 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number1 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number2 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number2 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number3 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number3 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number4 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number4 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number5 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number5 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Duration1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_LinkedFields (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Overallocated (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall AppendNotes (
        /*[in]*/ BSTR Value ) = 0;
      virtual HRESULT __stdcall TimeScaleData (
        /*[in]*/ VARIANT StartDate,
        /*[in]*/ VARIANT EndDate,
        /*[in]*/ enum PjAssignmentTimescaledData Type,
        /*[in]*/ enum PjTimescaleUnit TimeScaleUnit,
        /*[in]*/ long Count,
        /*[out,retval]*/ struct TimeScaleValues * * retval ) = 0;
      virtual HRESULT __stdcall get_TaskSummaryName (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_LevelingDelay (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_LevelingDelay (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineStart (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineStart (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineFinish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineFinish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Hyperlink (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Hyperlink (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkAddress (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkAddress (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkSubAddress (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkSubAddress (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkHREF (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkHREF (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Cost4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Cost10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Cost10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Date10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Date10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Duration10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Duration10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Flag20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Flag20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Number6 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number6 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number7 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number7 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number8 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number8 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number9 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number9 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number10 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number10 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number11 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number11 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number12 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number12 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number13 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number13 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number14 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number14 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number15 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number15 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number16 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number16 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number17 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number17 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number18 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number18 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number19 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number19 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Number20 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_Number20 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_Start6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Start10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Text11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Text30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Text30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_CV (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_WorkVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_StartVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_FinishVariance (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_VAC (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_FixedMaterialAssignment (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_ResourceType (
        /*[out,retval]*/ enum PjResourceTypes * retval ) = 0;
      virtual HRESULT __stdcall get_HyperlinkScreenTip (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_HyperlinkScreenTip (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Work (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Work (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Cost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Cost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_TaskOutlineNumber (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseCost10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseCost10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate21 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate21 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate22 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate22 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate23 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate23 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate24 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate24 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate25 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate25 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate26 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate26 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate27 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate27 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate28 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate28 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate29 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate29 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDate30 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDate30 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseDuration10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseDuration10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag1 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag1 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag2 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag2 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag3 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag3 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag4 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag4 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag5 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag5 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag6 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag6 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag7 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag7 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag8 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag8 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag9 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag9 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag10 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag10 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag11 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag11 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag12 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag12 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag13 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag13 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag14 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag14 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag15 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag15 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag16 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag16 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag17 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag17 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag18 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag18 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag19 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag19 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseFlag20 (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseFlag20 (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber1 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber1 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber2 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber2 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber3 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber3 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber4 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber4 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber5 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber5 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber6 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber6 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber7 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber7 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber8 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber8 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber9 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber9 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber10 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber10 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber11 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber11 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber12 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber12 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber13 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber13 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber14 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber14 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber15 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber15 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber16 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber16 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber17 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber17 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber18 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber18 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber19 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber19 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber20 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber20 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber21 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber21 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber22 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber22 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber23 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber23 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber24 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber24 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber25 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber25 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber26 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber26 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber27 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber27 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber28 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber28 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber29 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber29 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber30 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber30 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber31 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber31 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber32 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber32 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber33 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber33 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber34 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber34 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber35 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber35 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber36 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber36 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber37 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber37 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber38 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber38 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber39 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber39 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseNumber40 (
        /*[out,retval]*/ double * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseNumber40 (
        /*[in]*/ double retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText30 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText30 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText31 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText31 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText32 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText32 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText33 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText33 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText34 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText34 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText35 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText35 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText36 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText36 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText37 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText37 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText38 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText38 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText39 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText39 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseText40 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseText40 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode1 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode1 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode2 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode2 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode3 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode3 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode4 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode4 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode5 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode5 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode6 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode6 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode7 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode7 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode8 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode8 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode9 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode9 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode10 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode10 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode11 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode11 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode12 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode12 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode13 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode13 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode14 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode14 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode15 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode15 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode16 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode16 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode17 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode17 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode18 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode18 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode19 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode19 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceOutlineCode29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceOutlineCode29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceRBS (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceRBS (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ResourceRequestType (
        /*[out,retval]*/ enum PjResourceRequestType * retval ) = 0;
      virtual HRESULT __stdcall put_ResourceRequestType (
        /*[in]*/ enum PjResourceRequestType retval ) = 0;
      virtual HRESULT __stdcall EnterpriseTeamMember (
        /*[in]*/ IDispatch * Project,
        /*[out,retval]*/ VARIANT_BOOL * retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue20 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue20 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue21 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue21 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue22 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue22 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue23 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue23 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue24 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue24 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue25 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue25 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue26 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue26 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue27 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue27 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue28 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue28 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_EnterpriseResourceMultiValue29 (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_EnterpriseResourceMultiValue29 (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_ActualWorkProtected (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualWorkProtected (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_ActualOvtWorkProtected (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_ActualOvtWorkProtected (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Created (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Created (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_WBS (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_BookingType (
        /*[out,retval]*/ enum PjBookingTypes * retval ) = 0;
      virtual HRESULT __stdcall put_BookingType (
        /*[in]*/ enum PjBookingTypes retval ) = 0;
      virtual HRESULT __stdcall get_Guid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_TaskGuid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_ResourceGuid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_Summary (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_Owner (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Owner (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineBudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineBudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_BaselineBudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_BaselineBudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline1BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline1BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline2BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline2BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline3BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline3BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline4BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline4BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline5BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline5BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline6BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline6BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline7BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline7BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline8BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline8BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline9BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline9BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10BudgetWork (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10BudgetWork (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Baseline10BudgetCost (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Baseline10BudgetCost (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Task (
        /*[out,retval]*/ struct Task * * retval ) = 0;
      virtual HRESULT __stdcall get_Resource (
        /*[out,retval]*/ struct Resource * * retval ) = 0;
      virtual HRESULT __stdcall Replan (
        /*[in]*/ enum PjAssignmentReplanAction action ) = 0;
};

struct __declspec(uuid("000c0c58-0000-0000-c000-000000000046"))
PayRate : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_EffectiveDate (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_StandardRate (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_StandardRate (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_OvertimeRate (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_OvertimeRate (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_CostPerUse (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_CostPerUse (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Resource * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c57-0000-0000-c000-000000000046"))
PayRates : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct PayRate * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT EffectiveDate,
        /*[in]*/ VARIANT StdRate,
        /*[in]*/ VARIANT OvtRate,
        /*[in]*/ VARIANT CostPerUse,
        /*[out,retval]*/ struct PayRate * * pDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Resource * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c56-0000-0000-c000-000000000046"))
CostRateTable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * tblName ) = 0;
      virtual HRESULT __stdcall get_PayRates (
        /*[out,retval]*/ struct PayRates * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Resource * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c55-0000-0000-c000-000000000046"))
CostRateTables : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct CostRateTable * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Resource * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("1251566d-2bdf-11d2-9eac-00c04fb92e6f"))
Availability : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_AvailableFrom (
        /*[out,retval]*/ VARIANT * pFromDate ) = 0;
      virtual HRESULT __stdcall put_AvailableFrom (
        /*[in]*/ VARIANT pFromDate ) = 0;
      virtual HRESULT __stdcall get_AvailableTo (
        /*[out,retval]*/ VARIANT * pToDate ) = 0;
      virtual HRESULT __stdcall put_AvailableTo (
        /*[in]*/ VARIANT pToDate ) = 0;
      virtual HRESULT __stdcall get_AvailableUnit (
        /*[out,retval]*/ double * pUnit ) = 0;
      virtual HRESULT __stdcall put_AvailableUnit (
        /*[in]*/ double pUnit ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Resource * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("1251566c-2bdf-11d2-9eac-00c04fb92e6f"))
Availabilities : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Availability * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT AvailableFrom,
        /*[in]*/ VARIANT AvailableTo,
        /*[in]*/ double AvailableUnit,
        /*[out,retval]*/ struct Availability * * pDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Resource * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c42-0000-0000-c000-000000000046"))
Resources : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * retval ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_UniqueID (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct Resource * * retval ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Before,
        /*[out,retval]*/ struct Resource * * retval ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Resource * * retval ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
};

struct __declspec(uuid("000c0c46-0000-0000-c000-000000000046"))
Assignments : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * retval ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_UniqueID (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct Assignment * * retval ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT TaskID,
        /*[in]*/ VARIANT ResourceID,
        /*[in]*/ VARIANT Units,
        /*[out,retval]*/ struct Assignment * * retval ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Assignment * * retval ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
};

struct __declspec(uuid("9dd14142-f0a9-4692-8288-a6835f93dc8a"))
ActualStartDrivers : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct Assignment * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_TotalDetectedCount (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Task * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("9dd14145-f0a9-4692-8288-a6835f93dc8a"))
CalendarDrivers : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct Resource * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_TotalDetectedCount (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Task * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("9dd14146-f0a9-4692-8288-a6835f93dc8a"))
OverAllocatedAssignments : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct Assignment * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_TotalDetectedCount (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Task * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("9dd14141-f0a9-4692-8288-a6835f93dc8a"))
StartDriver : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ActualStartDrivers (
        /*[out,retval]*/ struct ActualStartDrivers * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_PredecessorDrivers (
        /*[out,retval]*/ struct PredecessorDrivers * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_ChildTaskDrivers (
        /*[out,retval]*/ struct ChildDrivers * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_CalendarDrivers (
        /*[out,retval]*/ struct CalendarDrivers * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Task * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Suggestions (
        /*[out,retval]*/ long * Suggestions ) = 0;
      virtual HRESULT __stdcall get_Warnings (
        /*[out,retval]*/ long * Warnings ) = 0;
      virtual HRESULT __stdcall get_OverAllocatedAssignments (
        /*[in]*/ enum PjOverallocationType overallocationType,
        /*[out,retval]*/ struct OverAllocatedAssignments * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_EffectiveDateDifference (
        /*[in]*/ VARIANT StartDate,
        /*[in]*/ VARIANT FinishDate,
        /*[out,retval]*/ VARIANT * difference ) = 0;
      virtual HRESULT __stdcall get_EffectiveDateAdd (
        /*[in]*/ VARIANT Date,
        /*[in]*/ VARIANT Duration,
        /*[out,retval]*/ VARIANT * result ) = 0;
      virtual HRESULT __stdcall get_EffectiveDateSubtract (
        /*[in]*/ VARIANT Date,
        /*[in]*/ VARIANT Duration,
        /*[out,retval]*/ VARIANT * result ) = 0;
};

struct __declspec(uuid("000c0c43-0000-0000-c000-000000000046"))
Calendar : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * retval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall Period (
        /*[in]*/ VARIANT Start,
        /*[in]*/ VARIANT Finish,
        /*[out,retval]*/ struct Period * * retval ) = 0;
      virtual HRESULT __stdcall get_Years (
        /*[out,retval]*/ struct Years * * retval ) = 0;
      virtual HRESULT __stdcall get_WeekDays (
        /*[out,retval]*/ struct WeekDays * * retval ) = 0;
      virtual HRESULT __stdcall Reset ( ) = 0;
      virtual HRESULT __stdcall get_BaseCalendar (
        /*[out,retval]*/ struct Calendar * * retval ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_Enterprise (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall get_Guid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_ResourceGuid (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_Exceptions (
        /*[out,retval]*/ struct Exceptions * * retval ) = 0;
      virtual HRESULT __stdcall get_WorkWeeks (
        /*[out,retval]*/ struct WorkWeeks * * retval ) = 0;
};

struct __declspec(uuid("000c0c4f-0000-0000-c000-000000000046"))
WeekDay : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Calendar (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift1 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift2 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift3 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Working (
        /*[out,retval]*/ VARIANT_BOOL * fWorking ) = 0;
      virtual HRESULT __stdcall put_Working (
        /*[in]*/ VARIANT fWorking ) = 0;
      virtual HRESULT __stdcall Default ( ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ short * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Shift4 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift5 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c4e-0000-0000-c000-000000000046"))
WeekDays : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct WeekDay * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c49-0000-0000-c000-000000000046"))
Period : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Calendar (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift1 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift2 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift3 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Working (
        /*[out,retval]*/ VARIANT_BOOL * fWorking ) = 0;
      virtual HRESULT __stdcall put_Working (
        /*[in]*/ VARIANT fWorking ) = 0;
      virtual HRESULT __stdcall Default ( ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift4 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift5 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c44-0000-0000-c000-000000000046"))
Calendars : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * retval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * retval ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * retval ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Calendar * * retval ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
};

struct __declspec(uuid("936f4d59-007b-4f7b-8932-90a40fc44391"))
Exception : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Occurrences (
        /*[out,retval]*/ long * pValue ) = 0;
      virtual HRESULT __stdcall put_Occurrences (
        /*[in]*/ long pValue ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum PjExceptionType * pValue ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum PjExceptionType pValue ) = 0;
      virtual HRESULT __stdcall get_Period (
        /*[out,retval]*/ long * pValue ) = 0;
      virtual HRESULT __stdcall put_Period (
        /*[in]*/ long pValue ) = 0;
      virtual HRESULT __stdcall get_DaysOfWeek (
        /*[out,retval]*/ long * pValue ) = 0;
      virtual HRESULT __stdcall put_DaysOfWeek (
        /*[in]*/ long pValue ) = 0;
      virtual HRESULT __stdcall get_MonthPosition (
        /*[out,retval]*/ enum PjExceptionPosition * pValue ) = 0;
      virtual HRESULT __stdcall put_MonthPosition (
        /*[in]*/ enum PjExceptionPosition pValue ) = 0;
      virtual HRESULT __stdcall get_MonthItem (
        /*[out,retval]*/ enum PjExceptionItem * pValue ) = 0;
      virtual HRESULT __stdcall put_MonthItem (
        /*[in]*/ enum PjExceptionItem pValue ) = 0;
      virtual HRESULT __stdcall get_Month (
        /*[out,retval]*/ enum PjMonth * pValue ) = 0;
      virtual HRESULT __stdcall put_Month (
        /*[in]*/ enum PjMonth pValue ) = 0;
      virtual HRESULT __stdcall get_MonthDay (
        /*[out,retval]*/ long * pValue ) = 0;
      virtual HRESULT __stdcall put_MonthDay (
        /*[in]*/ long pValue ) = 0;
      virtual HRESULT __stdcall get_Shift1 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift2 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift3 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift4 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift5 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
};

struct __declspec(uuid("9dbaec97-ada1-4488-8845-818e734f182e"))
Exceptions : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Exception * * ppDispatch ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum PjExceptionType Type,
        /*[in]*/ VARIANT Start,
        /*[in]*/ VARIANT Finish,
        /*[in]*/ VARIANT Occurrences,
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Period,
        /*[in]*/ VARIANT DaysOfWeek,
        /*[in]*/ VARIANT MonthPosition,
        /*[in]*/ VARIANT MonthItem,
        /*[in]*/ VARIANT Month,
        /*[in]*/ VARIANT MonthDay,
        /*[out,retval]*/ struct Exception * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c4a-0000-0000-c000-000000000046"))
Years : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Year * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c4c-0000-0000-c000-000000000046"))
Months : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Year * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Month * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c4b-0000-0000-c000-000000000046"))
Year : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Calendar (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift1 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift2 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift3 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Working (
        /*[out,retval]*/ VARIANT_BOOL * fWorking ) = 0;
      virtual HRESULT __stdcall put_Working (
        /*[in]*/ VARIANT fWorking ) = 0;
      virtual HRESULT __stdcall Default ( ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ short * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Months (
        /*[out,retval]*/ struct Months * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift4 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift5 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c51-0000-0000-c000-000000000046"))
Days : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Month * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Day * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c4d-0000-0000-c000-000000000046"))
Month : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Calendar (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift1 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift2 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift3 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Working (
        /*[out,retval]*/ VARIANT_BOOL * fWorking ) = 0;
      virtual HRESULT __stdcall put_Working (
        /*[in]*/ VARIANT fWorking ) = 0;
      virtual HRESULT __stdcall Default ( ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Year * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ short * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Days (
        /*[out,retval]*/ struct Days * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift4 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift5 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
};

struct __declspec(uuid("000c0c52-0000-0000-c000-000000000046"))
Day : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Calendar (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift1 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift2 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift3 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Working (
        /*[out,retval]*/ VARIANT_BOOL * fWorking ) = 0;
      virtual HRESULT __stdcall put_Working (
        /*[in]*/ VARIANT fWorking ) = 0;
      virtual HRESULT __stdcall Default ( ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Month * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ short * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Shift4 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift5 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
};

struct __declspec(uuid("11589054-69f0-11d2-b889-00c04fb90729"))
TaskGroups : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR FieldName,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("11589055-69f0-11d2-b889-00c04fb90729"))
ResourceGroups : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR FieldName,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("11589051-69f0-11d2-b889-00c04fb90729"))
Group : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * szName ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR szName ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * lIndex ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_GroupCriteria (
        /*[out,retval]*/ struct GroupCriteria * * ppDispatch ) = 0;
      virtual HRESULT __stdcall put_GroupCriteria (
        /*[in]*/ struct GroupCriteria * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_ShowSummary (
        /*[out,retval]*/ VARIANT_BOOL * fShowSummary ) = 0;
      virtual HRESULT __stdcall put_ShowSummary (
        /*[in]*/ VARIANT_BOOL fShowSummary ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_GroupAssignments (
        /*[out,retval]*/ VARIANT_BOOL * fGroupAssignments ) = 0;
      virtual HRESULT __stdcall put_GroupAssignments (
        /*[in]*/ VARIANT_BOOL fGroupAssignments ) = 0;
};

struct __declspec(uuid("11589053-69f0-11d2-b889-00c04fb90729"))
GroupCriterion : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_FieldName (
        /*[out,retval]*/ BSTR * szName ) = 0;
      virtual HRESULT __stdcall put_FieldName (
        /*[in]*/ BSTR szName ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * lIndex ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Group * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Ascending (
        /*[out,retval]*/ VARIANT_BOOL * fAscending ) = 0;
      virtual HRESULT __stdcall put_Ascending (
        /*[in]*/ VARIANT_BOOL fAscending ) = 0;
      virtual HRESULT __stdcall get_FontName (
        /*[out,retval]*/ BSTR * FontName ) = 0;
      virtual HRESULT __stdcall put_FontName (
        /*[in]*/ BSTR FontName ) = 0;
      virtual HRESULT __stdcall get_FontSize (
        /*[out,retval]*/ int * FontSize ) = 0;
      virtual HRESULT __stdcall put_FontSize (
        /*[in]*/ int FontSize ) = 0;
      virtual HRESULT __stdcall get_FontBold (
        /*[out,retval]*/ VARIANT_BOOL * FontBold ) = 0;
      virtual HRESULT __stdcall put_FontBold (
        /*[in]*/ VARIANT_BOOL FontBold ) = 0;
      virtual HRESULT __stdcall get_FontItalic (
        /*[out,retval]*/ VARIANT_BOOL * FontItalic ) = 0;
      virtual HRESULT __stdcall put_FontItalic (
        /*[in]*/ VARIANT_BOOL FontItalic ) = 0;
      virtual HRESULT __stdcall get_FontUnderLine (
        /*[out,retval]*/ VARIANT_BOOL * FontUnderLine ) = 0;
      virtual HRESULT __stdcall put_FontUnderLine (
        /*[in]*/ VARIANT_BOOL FontUnderLine ) = 0;
      virtual HRESULT __stdcall get_FontColor (
        /*[out,retval]*/ enum PjColor * FontColor ) = 0;
      virtual HRESULT __stdcall put_FontColor (
        /*[in]*/ enum PjColor FontColor ) = 0;
      virtual HRESULT __stdcall get_CellColor (
        /*[out,retval]*/ enum PjColor * CellColor ) = 0;
      virtual HRESULT __stdcall put_CellColor (
        /*[in]*/ enum PjColor CellColor ) = 0;
      virtual HRESULT __stdcall get_Pattern (
        /*[out,retval]*/ enum PjBackgroundPattern * CellPattern ) = 0;
      virtual HRESULT __stdcall put_Pattern (
        /*[in]*/ enum PjBackgroundPattern CellPattern ) = 0;
      virtual HRESULT __stdcall get_GroupOn (
        /*[out,retval]*/ enum PjGroupOn * GroupOn ) = 0;
      virtual HRESULT __stdcall put_GroupOn (
        /*[in]*/ enum PjGroupOn GroupOn ) = 0;
      virtual HRESULT __stdcall get_StartAt (
        /*[out,retval]*/ VARIANT * StartAt ) = 0;
      virtual HRESULT __stdcall put_StartAt (
        /*[in]*/ VARIANT StartAt ) = 0;
      virtual HRESULT __stdcall get_GroupInterval (
        /*[out,retval]*/ VARIANT * GroupInterval ) = 0;
      virtual HRESULT __stdcall put_GroupInterval (
        /*[in]*/ VARIANT GroupInterval ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Assignment (
        /*[out,retval]*/ VARIANT_BOOL * fAssignment ) = 0;
      virtual HRESULT __stdcall put_Assignment (
        /*[in]*/ VARIANT_BOOL fAssignment ) = 0;
};

struct __declspec(uuid("11589052-69f0-11d2-b889-00c04fb90729"))
GroupCriteria : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct GroupCriterion * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR FieldName,
        /*[in]*/ VARIANT_BOOL Ascending,
        /*[in]*/ BSTR FontName,
        /*[in]*/ int FontSize,
        /*[in]*/ VARIANT_BOOL FontBold,
        /*[in]*/ VARIANT_BOOL FontItalic,
        /*[in]*/ VARIANT_BOOL FontUnderLine,
        /*[in]*/ enum PjColor FontColor,
        /*[in]*/ enum PjColor CellColor,
        /*[in]*/ enum PjBackgroundPattern Pattern,
        /*[in]*/ enum PjGroupOn GroupOn,
        /*[in]*/ VARIANT StartAt,
        /*[in]*/ VARIANT GroupInterval,
        /*[out,retval]*/ struct GroupCriterion * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Group * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("11589050-69f0-11d2-b889-00c04fb90729"))
Groups : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR FieldName,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Group * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("b4097887-ec12-4683-9622-9974ef26353c"))
ViewsSingle : Views
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ enum PjViewScreen Screen,
        /*[in]*/ VARIANT_BOOL ShowInMenu,
        /*[in]*/ VARIANT Table,
        /*[in]*/ VARIANT Filter,
        /*[in]*/ VARIANT Group,
        /*[in]*/ VARIANT_BOOL HighlightFilt,
        /*[out,retval]*/ struct ViewSingle * * ppViewSingle ) = 0;
};

struct __declspec(uuid("ce4f7d83-369b-43cf-96a8-29c2de2b8658"))
ViewsCombination : Views
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT TopView,
        /*[in]*/ VARIANT BottomView,
        /*[in]*/ VARIANT_BOOL ShowInMenu,
        /*[out,retval]*/ struct ViewCombination * * ppViewCombination ) = 0;
};

struct __declspec(uuid("f15fde9e-fdc1-44d2-a0d0-249ad48f58fe"))
ViewSingle : View
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Table (
        /*[out,retval]*/ struct Table * * Table ) = 0;
      virtual HRESULT __stdcall put_Table (
        /*[in]*/ VARIANT Table ) = 0;
      virtual HRESULT __stdcall get_Filter (
        /*[out,retval]*/ struct Filter * * Filter ) = 0;
      virtual HRESULT __stdcall put_Filter (
        /*[in]*/ VARIANT Filter ) = 0;
      virtual HRESULT __stdcall get_Group (
        /*[out,retval]*/ struct Group * * Group ) = 0;
      virtual HRESULT __stdcall put_Group (
        /*[in]*/ VARIANT Group ) = 0;
      virtual HRESULT __stdcall get_HighlightFilter (
        /*[out,retval]*/ VARIANT_BOOL * HighlightFilter ) = 0;
      virtual HRESULT __stdcall put_HighlightFilter (
        /*[in]*/ VARIANT_BOOL HighlightFilter ) = 0;
};

struct __declspec(uuid("0880e27c-c621-4349-96ad-56520c827e14"))
ViewCombination : View
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_TopView (
        /*[out,retval]*/ struct ViewSingle * * TopView ) = 0;
      virtual HRESULT __stdcall put_TopView (
        /*[in]*/ VARIANT TopView ) = 0;
      virtual HRESULT __stdcall get_BottomView (
        /*[out,retval]*/ struct ViewSingle * * BottomView ) = 0;
      virtual HRESULT __stdcall put_BottomView (
        /*[in]*/ VARIANT BottomView ) = 0;
};

struct __declspec(uuid("31e3eb5a-6339-43b0-b1b8-1aed03886aec"))
Tables : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Table * * Table ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ VARIANT Source,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Table * * Table ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ enum PjField Field,
        /*[in]*/ VARIANT_BOOL Task,
        /*[out,retval]*/ struct Table * * newtable ) = 0;
};

struct __declspec(uuid("54eff41a-4603-4771-80ee-f313bf9faec2"))
Table : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * Dispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * Dispatch ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_TableType (
        /*[out,retval]*/ enum PjItemType * Type ) = 0;
      virtual HRESULT __stdcall get_ShowInMenu (
        /*[out,retval]*/ VARIANT_BOOL * ShowInMenu ) = 0;
      virtual HRESULT __stdcall put_ShowInMenu (
        /*[in]*/ VARIANT_BOOL ShowInMenu ) = 0;
      virtual HRESULT __stdcall Apply ( ) = 0;
      virtual HRESULT __stdcall get_DateFormat (
        /*[out,retval]*/ enum PjDateFormat * Format ) = 0;
      virtual HRESULT __stdcall put_DateFormat (
        /*[in]*/ enum PjDateFormat Format ) = 0;
      virtual HRESULT __stdcall get_RowHeight (
        /*[out,retval]*/ long * Height ) = 0;
      virtual HRESULT __stdcall put_RowHeight (
        /*[in]*/ long Height ) = 0;
      virtual HRESULT __stdcall get_LockFirstColumn (
        /*[out,retval]*/ VARIANT_BOOL * Locked ) = 0;
      virtual HRESULT __stdcall put_LockFirstColumn (
        /*[in]*/ VARIANT_BOOL Locked ) = 0;
      virtual HRESULT __stdcall get_AdjustHeaderRowHeight (
        /*[out,retval]*/ VARIANT_BOOL * adjustable ) = 0;
      virtual HRESULT __stdcall put_AdjustHeaderRowHeight (
        /*[in]*/ VARIANT_BOOL adjustable ) = 0;
      virtual HRESULT __stdcall get_TableFields (
        /*[out,retval]*/ struct TableFields * * tfs ) = 0;
};

struct __declspec(uuid("747d4ba8-fb3b-4c2c-b615-02cb6ebf0ae7"))
TableField : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * Dispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Table * * Dispatch ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Field (
        /*[out,retval]*/ enum PjField * Field ) = 0;
      virtual HRESULT __stdcall put_Field (
        /*[in]*/ enum PjField Field ) = 0;
      virtual HRESULT __stdcall get_AlignData (
        /*[out,retval]*/ enum PjAlignment * Alignment ) = 0;
      virtual HRESULT __stdcall put_AlignData (
        /*[in]*/ enum PjAlignment Alignment ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * Width ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ long Width ) = 0;
      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * Title ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR Title ) = 0;
      virtual HRESULT __stdcall get_AlignTitle (
        /*[out,retval]*/ enum PjAlignment * Alignment ) = 0;
      virtual HRESULT __stdcall put_AlignTitle (
        /*[in]*/ enum PjAlignment Alignment ) = 0;
      virtual HRESULT __stdcall get_AutoWrap (
        /*[out,retval]*/ VARIANT_BOOL * AutoWrap ) = 0;
      virtual HRESULT __stdcall put_AutoWrap (
        /*[in]*/ VARIANT_BOOL AutoWrap ) = 0;
};

struct __declspec(uuid("bf6d2103-92d3-4162-9816-a3d811bcf8ca"))
TableFields : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum PjField Field,
        /*[in]*/ enum PjAlignment AlignData,
        /*[in]*/ long Width,
        /*[in]*/ BSTR Title,
        /*[in]*/ enum PjAlignment AlignTitle,
        /*[in]*/ long Before,
        /*[in]*/ VARIANT_BOOL AutoWrap,
        /*[out,retval]*/ struct TableField * * newtf ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * Dispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * Dispatch ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct TableField * * tf ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
};

struct __declspec(uuid("30dff087-4ddc-4166-93b2-a9c259c1e4ad"))
OutlineCode : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_FieldID (
        /*[out,retval]*/ enum PjCustomField * pFieldID ) = 0;
      virtual HRESULT __stdcall get_LinkedFieldID (
        /*[out,retval]*/ long * LinkedFieldID ) = 0;
      virtual HRESULT __stdcall put_LinkedFieldID (
        /*[in]*/ long LinkedFieldID ) = 0;
      virtual HRESULT __stdcall get_LookupTable (
        /*[out,retval]*/ struct LookupTable * * ppLookupTable ) = 0;
      virtual HRESULT __stdcall get_CodeMask (
        /*[out,retval]*/ struct CodeMask * * ppCodeMask ) = 0;
      virtual HRESULT __stdcall get_OnlyLookUpTableCodes (
        /*[out,retval]*/ VARIANT_BOOL * OnlyLookUpTableCodes ) = 0;
      virtual HRESULT __stdcall put_OnlyLookUpTableCodes (
        /*[in]*/ VARIANT_BOOL OnlyLookUpTableCodes ) = 0;
      virtual HRESULT __stdcall get_OnlyCompleteCodes (
        /*[out,retval]*/ VARIANT_BOOL * OnlyCompleteCodes ) = 0;
      virtual HRESULT __stdcall put_OnlyCompleteCodes (
        /*[in]*/ VARIANT_BOOL OnlyCompleteCodes ) = 0;
      virtual HRESULT __stdcall get_OnlyLeaves (
        /*[out,retval]*/ VARIANT_BOOL * OnlyLeaves ) = 0;
      virtual HRESULT __stdcall put_OnlyLeaves (
        /*[in]*/ VARIANT_BOOL OnlyLeaves ) = 0;
      virtual HRESULT __stdcall get_MatchGeneric (
        /*[out,retval]*/ VARIANT_BOOL * MatchGeneric ) = 0;
      virtual HRESULT __stdcall put_MatchGeneric (
        /*[in]*/ VARIANT_BOOL MatchGeneric ) = 0;
      virtual HRESULT __stdcall get_RequiredCode (
        /*[out,retval]*/ VARIANT_BOOL * RequiredCode ) = 0;
      virtual HRESULT __stdcall put_RequiredCode (
        /*[in]*/ VARIANT_BOOL RequiredCode ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_SortOrder (
        /*[out,retval]*/ enum PjListOrder * SortOrder ) = 0;
      virtual HRESULT __stdcall put_SortOrder (
        /*[in]*/ enum PjListOrder SortOrder ) = 0;
      virtual HRESULT __stdcall get_DefaultValue (
        /*[out,retval]*/ BSTR * DefaultValue ) = 0;
      virtual HRESULT __stdcall put_DefaultValue (
        /*[in]*/ BSTR DefaultValue ) = 0;
};

struct __declspec(uuid("4269779b-f035-4e2f-abdd-54b6d94a2a03"))
OutlineCodes : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum PjCustomField FieldID,
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ struct OutlineCode * * newolc ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct OutlineCode * * olc ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
};

struct __declspec(uuid("c19e7deb-c19b-4294-bc60-5b2d99c00398"))
LookupTableEntry : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct OutlineCode * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_ParentEntry (
        /*[out,retval]*/ struct LookupTableEntry * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Level (
        /*[out,retval]*/ long * Level ) = 0;
      virtual HRESULT __stdcall put_Level (
        /*[in]*/ long Level ) = 0;
      virtual HRESULT __stdcall get_UniqueID (
        /*[out,retval]*/ long * UniqueID ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR Description ) = 0;
      virtual HRESULT __stdcall get_IsValid (
        /*[out,retval]*/ VARIANT_BOOL * IsValid ) = 0;
      virtual HRESULT __stdcall get_FullName (
        /*[out,retval]*/ BSTR * FullName ) = 0;
      virtual HRESULT __stdcall get_Cookie (
        /*[out,retval]*/ BSTR * Cookie ) = 0;
      virtual HRESULT __stdcall get_LocalizedCookie (
        /*[out,retval]*/ BSTR * Cookie ) = 0;
};

struct __declspec(uuid("da33f25e-ad36-48b9-9cb6-cdb0cf6ee070"))
LookupTable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall AddChild (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT ParentUniqueID,
        /*[out,retval]*/ struct LookupTableEntry * * newlute ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct LookupTableEntry * * lute ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct OutlineCode * * Dispatch ) = 0;
};

struct __declspec(uuid("e75e1380-8623-41c9-9920-508f676c4575"))
CodeMaskLevel : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Level (
        /*[out,retval]*/ long * Level ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct OutlineCode * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Sequence (
        /*[out,retval]*/ enum PjCustomOutlineCodeSequence * Sequence ) = 0;
      virtual HRESULT __stdcall put_Sequence (
        /*[in]*/ enum PjCustomOutlineCodeSequence Sequence ) = 0;
      virtual HRESULT __stdcall get_Length (
        /*[out,retval]*/ VARIANT * Length ) = 0;
      virtual HRESULT __stdcall put_Length (
        /*[in]*/ VARIANT Length ) = 0;
      virtual HRESULT __stdcall get_Separator (
        /*[out,retval]*/ BSTR * Separator ) = 0;
      virtual HRESULT __stdcall put_Separator (
        /*[in]*/ BSTR Separator ) = 0;
};

struct __declspec(uuid("4cc10f2b-7df1-413c-a44d-9ab35adfd9ae"))
CodeMask : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum PjCustomOutlineCodeSequence Sequence,
        /*[in]*/ VARIANT Length,
        /*[in]*/ VARIANT Separator,
        /*[out,retval]*/ struct CodeMaskLevel * * newcml ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct CodeMaskLevel * * cml ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct OutlineCode * * Dispatch ) = 0;
};

struct __declspec(uuid("22228b77-f739-46a2-bf45-eee43a936f06"))
WorkWeek : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Start (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Start (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_Finish (
        /*[out,retval]*/ VARIANT * retval ) = 0;
      virtual HRESULT __stdcall put_Finish (
        /*[in]*/ VARIANT retval ) = 0;
      virtual HRESULT __stdcall get_WeekDays (
        /*[out,retval]*/ struct WorkWeekDays * * ppDispatch ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
};

struct __declspec(uuid("1137eff0-691f-4f78-9647-40fe8e500d34"))
WorkWeeks : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct WorkWeek * * ppDispatch ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT Start,
        /*[in]*/ VARIANT Finish,
        /*[in]*/ VARIANT Name,
        /*[out,retval]*/ struct WorkWeek * * ppDispatch ) = 0;
};

struct __declspec(uuid("9bc789c9-50c6-476f-a96c-d46e95b4c901"))
WorkWeekDay : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Calendar (
        /*[out,retval]*/ struct Calendar * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift1 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift2 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift3 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Working (
        /*[out,retval]*/ VARIANT_BOOL * fWorking ) = 0;
      virtual HRESULT __stdcall put_Working (
        /*[in]*/ VARIANT fWorking ) = 0;
      virtual HRESULT __stdcall Default ( ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct WorkWeek * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ short * pwIndx ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Shift4 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Shift5 (
        /*[out,retval]*/ struct Shift * * ppDispatch ) = 0;
};

struct __declspec(uuid("1f4f463f-eb4b-4d2e-86ed-61a9cfa41e89"))
WorkWeekDays : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * wCount ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct WorkWeek * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct WorkWeekDay * * ppDispatch ) = 0;
};

struct __declspec(uuid("1158905a-69f0-11d2-b889-00c04fb90729"))
TaskGroups2 : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR FieldName,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("1158905b-69f0-11d2-b889-00c04fb90729"))
ResourceGroups2 : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR FieldName,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("11589058-69f0-11d2-b889-00c04fb90729"))
Group2 : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * szName ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR szName ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * lIndex ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_GroupCriteria (
        /*[out,retval]*/ struct GroupCriteria2 * * ppDispatch ) = 0;
      virtual HRESULT __stdcall put_GroupCriteria (
        /*[in]*/ struct GroupCriteria2 * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_ShowSummary (
        /*[out,retval]*/ VARIANT_BOOL * fShowSummary ) = 0;
      virtual HRESULT __stdcall put_ShowSummary (
        /*[in]*/ VARIANT_BOOL fShowSummary ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_GroupAssignments (
        /*[out,retval]*/ VARIANT_BOOL * fGroupAssignments ) = 0;
      virtual HRESULT __stdcall put_GroupAssignments (
        /*[in]*/ VARIANT_BOOL fGroupAssignments ) = 0;
      virtual HRESULT __stdcall get_MaintainHierarchy (
        /*[out,retval]*/ VARIANT_BOOL * fMaintainHierarchy ) = 0;
      virtual HRESULT __stdcall put_MaintainHierarchy (
        /*[in]*/ VARIANT_BOOL fMaintainHierarchy ) = 0;
};

struct __declspec(uuid("11589057-69f0-11d2-b889-00c04fb90729"))
GroupCriterion2 : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_FieldName (
        /*[out,retval]*/ BSTR * szName ) = 0;
      virtual HRESULT __stdcall put_FieldName (
        /*[in]*/ BSTR szName ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * lIndex ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Group2 * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Ascending (
        /*[out,retval]*/ VARIANT_BOOL * fAscending ) = 0;
      virtual HRESULT __stdcall put_Ascending (
        /*[in]*/ VARIANT_BOOL fAscending ) = 0;
      virtual HRESULT __stdcall get_FontName (
        /*[out,retval]*/ BSTR * FontName ) = 0;
      virtual HRESULT __stdcall put_FontName (
        /*[in]*/ BSTR FontName ) = 0;
      virtual HRESULT __stdcall get_FontSize (
        /*[out,retval]*/ int * FontSize ) = 0;
      virtual HRESULT __stdcall put_FontSize (
        /*[in]*/ int FontSize ) = 0;
      virtual HRESULT __stdcall get_FontBold (
        /*[out,retval]*/ VARIANT_BOOL * FontBold ) = 0;
      virtual HRESULT __stdcall put_FontBold (
        /*[in]*/ VARIANT_BOOL FontBold ) = 0;
      virtual HRESULT __stdcall get_FontItalic (
        /*[out,retval]*/ VARIANT_BOOL * FontItalic ) = 0;
      virtual HRESULT __stdcall put_FontItalic (
        /*[in]*/ VARIANT_BOOL FontItalic ) = 0;
      virtual HRESULT __stdcall get_FontUnderLine (
        /*[out,retval]*/ VARIANT_BOOL * FontUnderLine ) = 0;
      virtual HRESULT __stdcall put_FontUnderLine (
        /*[in]*/ VARIANT_BOOL FontUnderLine ) = 0;
      virtual HRESULT __stdcall get_FontColor (
        /*[out,retval]*/ enum PjColor * FontColor ) = 0;
      virtual HRESULT __stdcall put_FontColor (
        /*[in]*/ enum PjColor FontColor ) = 0;
      virtual HRESULT __stdcall get_CellColor (
        /*[out,retval]*/ enum PjColor * CellColor ) = 0;
      virtual HRESULT __stdcall put_CellColor (
        /*[in]*/ enum PjColor CellColor ) = 0;
      virtual HRESULT __stdcall get_Pattern (
        /*[out,retval]*/ enum PjBackgroundPattern * CellPattern ) = 0;
      virtual HRESULT __stdcall put_Pattern (
        /*[in]*/ enum PjBackgroundPattern CellPattern ) = 0;
      virtual HRESULT __stdcall get_GroupOn (
        /*[out,retval]*/ enum PjGroupOn * GroupOn ) = 0;
      virtual HRESULT __stdcall put_GroupOn (
        /*[in]*/ enum PjGroupOn GroupOn ) = 0;
      virtual HRESULT __stdcall get_StartAt (
        /*[out,retval]*/ VARIANT * StartAt ) = 0;
      virtual HRESULT __stdcall put_StartAt (
        /*[in]*/ VARIANT StartAt ) = 0;
      virtual HRESULT __stdcall get_GroupInterval (
        /*[out,retval]*/ VARIANT * GroupInterval ) = 0;
      virtual HRESULT __stdcall put_GroupInterval (
        /*[in]*/ VARIANT GroupInterval ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Assignment (
        /*[out,retval]*/ VARIANT_BOOL * fAssignment ) = 0;
      virtual HRESULT __stdcall put_Assignment (
        /*[in]*/ VARIANT_BOOL fAssignment ) = 0;
      virtual HRESULT __stdcall get_FontColorEx (
        /*[out,retval]*/ long * FontColor ) = 0;
      virtual HRESULT __stdcall put_FontColorEx (
        /*[in]*/ long FontColor ) = 0;
      virtual HRESULT __stdcall get_CellColorEx (
        /*[out,retval]*/ long * CellColor ) = 0;
      virtual HRESULT __stdcall put_CellColorEx (
        /*[in]*/ long CellColor ) = 0;
};

struct __declspec(uuid("11589056-69f0-11d2-b889-00c04fb90729"))
GroupCriteria2 : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct GroupCriterion2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR FieldName,
        /*[in]*/ VARIANT_BOOL Ascending,
        /*[in]*/ BSTR FontName,
        /*[in]*/ int FontSize,
        /*[in]*/ VARIANT_BOOL FontBold,
        /*[in]*/ VARIANT_BOOL FontItalic,
        /*[in]*/ VARIANT_BOOL FontUnderLine,
        /*[in]*/ enum PjColor FontColor,
        /*[in]*/ enum PjColor CellColor,
        /*[in]*/ enum PjBackgroundPattern Pattern,
        /*[in]*/ enum PjGroupOn GroupOn,
        /*[in]*/ VARIANT StartAt,
        /*[in]*/ VARIANT GroupInterval,
        /*[out,retval]*/ struct GroupCriterion2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Group2 * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall AddEx (
        /*[in]*/ BSTR FieldName,
        /*[in]*/ VARIANT_BOOL Ascending,
        /*[in]*/ BSTR FontName,
        /*[in]*/ int FontSize,
        /*[in]*/ VARIANT_BOOL FontBold,
        /*[in]*/ VARIANT_BOOL FontItalic,
        /*[in]*/ VARIANT_BOOL FontUnderLine,
        /*[in]*/ long FontColor,
        /*[in]*/ long CellColor,
        /*[in]*/ enum PjBackgroundPattern Pattern,
        /*[in]*/ enum PjGroupOn GroupOn,
        /*[in]*/ VARIANT StartAt,
        /*[in]*/ VARIANT GroupInterval,
        /*[out,retval]*/ struct GroupCriterion2 * * ppdisp ) = 0;
};

struct __declspec(uuid("11589059-69f0-11d2-b889-00c04fb90729"))
Groups2 : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pwIndx ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR FieldName,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Group2 * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
};

struct __declspec(uuid("ff59cfba-cb6f-4b92-a7d2-97d1cab6ebff"))
Reports : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppEnumVar ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Report * * Report ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ VARIANT Source,
        /*[in]*/ BSTR NewName,
        /*[out,retval]*/ struct Report * * Report ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ struct Report * * ppdisp ) = 0;
      virtual HRESULT __stdcall IsPresent (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ VARIANT_BOOL * pfPresent ) = 0;
};

struct __declspec(uuid("c4f74db0-e706-4ad5-9e71-ad5e6a0cf388"))
Report : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * Dispatch ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * Index ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _IProjectDoc * * Dispatch ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Apply ( ) = 0;
      virtual HRESULT __stdcall get_Shapes (
        /*[out,retval]*/ struct Shapes * * Shapes ) = 0;
};

struct __declspec(uuid("7300bad0-c853-475e-80a7-2fa3a286f91f"))
Shape : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall Apply ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Duplicate (
        /*[out,retval]*/ struct Shape * * Duplicate ) = 0;
      virtual HRESULT __stdcall Flip (
        /*[in]*/ enum Office::MsoFlipCmd FlipCmd ) = 0;
      virtual HRESULT __stdcall IncrementLeft (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementRotation (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementTop (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall PickUp ( ) = 0;
      virtual HRESULT __stdcall RerouteConnections ( ) = 0;
      virtual HRESULT __stdcall ScaleHeight (
        /*[in]*/ float Factor,
        /*[in]*/ enum Office::MsoTriState RelativeToOriginalSize,
        /*[in]*/ enum Office::MsoScaleFrom fScale ) = 0;
      virtual HRESULT __stdcall ScaleWidth (
        /*[in]*/ float Factor,
        /*[in]*/ enum Office::MsoTriState RelativeToOriginalSize,
        /*[in]*/ enum Office::MsoScaleFrom fScale ) = 0;
      virtual HRESULT __stdcall Select (
        /*[in]*/ VARIANT Replace = vtMissing ) = 0;
      virtual HRESULT __stdcall SetShapesDefaultProperties ( ) = 0;
      virtual HRESULT __stdcall Ungroup (
        /*[out,retval]*/ struct ShapeRange * * Ungroup ) = 0;
      virtual HRESULT __stdcall ZOrder (
        /*[in]*/ enum Office::MsoZOrderCmd ZOrderCmd ) = 0;
      virtual HRESULT __stdcall get_Adjustments (
        /*[out,retval]*/ struct Office::TangramAdjustments * * Adjustments ) = 0;
      virtual HRESULT __stdcall get_AutoShapeType (
        /*[out,retval]*/ enum Office::MsoAutoShapeType * AutoShapeType ) = 0;
      virtual HRESULT __stdcall put_AutoShapeType (
        /*[in]*/ enum Office::MsoAutoShapeType AutoShapeType ) = 0;
      virtual HRESULT __stdcall get_BlackWhiteMode (
        /*[out,retval]*/ enum Office::MsoBlackWhiteMode * BlackWhiteMode ) = 0;
      virtual HRESULT __stdcall put_BlackWhiteMode (
        /*[in]*/ enum Office::MsoBlackWhiteMode BlackWhiteMode ) = 0;
      virtual HRESULT __stdcall get_Callout (
        /*[out,retval]*/ struct Office::CalloutFormat * * Callout ) = 0;
      virtual HRESULT __stdcall get_ConnectionSiteCount (
        /*[out,retval]*/ int * ConnectionSiteCount ) = 0;
      virtual HRESULT __stdcall get_Connector (
        /*[out,retval]*/ enum Office::MsoTriState * Connector ) = 0;
      virtual HRESULT __stdcall get_ConnectorFormat (
        /*[out,retval]*/ struct Office::ConnectorFormat * * ConnectorFormat ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct Office::FillFormat * * Fill ) = 0;
      virtual HRESULT __stdcall get_GroupItems (
        /*[out,retval]*/ struct Office::GroupShapes * * GroupItems ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ float * Height ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ float Height ) = 0;
      virtual HRESULT __stdcall get_HorizontalFlip (
        /*[out,retval]*/ enum Office::MsoTriState * HorizontalFlip ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ float * Left ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ float Left ) = 0;
      virtual HRESULT __stdcall get_Line (
        /*[out,retval]*/ struct Office::LineFormat * * Line ) = 0;
      virtual HRESULT __stdcall get_LockAspectRatio (
        /*[out,retval]*/ enum Office::MsoTriState * LockAspectRatio ) = 0;
      virtual HRESULT __stdcall put_LockAspectRatio (
        /*[in]*/ enum Office::MsoTriState LockAspectRatio ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Nodes (
        /*[out,retval]*/ struct Office::ShapeNodes * * Nodes ) = 0;
      virtual HRESULT __stdcall get_Rotation (
        /*[out,retval]*/ float * Rotation ) = 0;
      virtual HRESULT __stdcall put_Rotation (
        /*[in]*/ float Rotation ) = 0;
      virtual HRESULT __stdcall get_PictureFormat (
        /*[out,retval]*/ struct Office::PictureFormat * * Picture ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ struct Office::ShadowFormat * * Shadow ) = 0;
      virtual HRESULT __stdcall get_TextEffect (
        /*[out,retval]*/ struct Office::TextEffectFormat * * TextEffect ) = 0;
      virtual HRESULT __stdcall get_TextFrame (
        /*[out,retval]*/ struct Office::TextFrame * * TextFrame ) = 0;
      virtual HRESULT __stdcall get_ThreeD (
        /*[out,retval]*/ struct Office::ThreeDFormat * * ThreeD ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ float * Top ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ float Top ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum Office::MsoShapeType * Type ) = 0;
      virtual HRESULT __stdcall get_VerticalFlip (
        /*[out,retval]*/ enum Office::MsoTriState * VerticalFlip ) = 0;
      virtual HRESULT __stdcall get_Vertices (
        /*[out,retval]*/ VARIANT * Vertices ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum Office::MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum Office::MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ float * Width ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ float Width ) = 0;
      virtual HRESULT __stdcall get_ZOrderPosition (
        /*[out,retval]*/ int * ZOrderPosition ) = 0;
      virtual HRESULT __stdcall get_Script (
        /*[out,retval]*/ struct Office::Script * * Script ) = 0;
      virtual HRESULT __stdcall get_AlternativeText (
        /*[out,retval]*/ BSTR * AlternativeText ) = 0;
      virtual HRESULT __stdcall put_AlternativeText (
        /*[in]*/ BSTR AlternativeText ) = 0;
      virtual HRESULT __stdcall get_Child (
        /*[out,retval]*/ enum Office::MsoTriState * Child ) = 0;
      virtual HRESULT __stdcall get_ParentGroup (
        /*[out,retval]*/ struct Shape * * Parent ) = 0;
      virtual HRESULT __stdcall get_CanvasItems (
        /*[out,retval]*/ struct Office::CanvasShapes * * CanvasShapes ) = 0;
      virtual HRESULT __stdcall get_ID (
        /*[out,retval]*/ int * pid ) = 0;
      virtual HRESULT __stdcall CanvasCropLeft (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropTop (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropRight (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropBottom (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall put_RTF (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_TextFrame2 (
        /*[out,retval]*/ struct Office::TextFrame2 * * Frame ) = 0;
      virtual HRESULT __stdcall Cut ( ) = 0;
      virtual HRESULT __stdcall Copy ( ) = 0;
      virtual HRESULT __stdcall get_HasChart (
        /*[out,retval]*/ enum Office::MsoTriState * pHasChart ) = 0;
      virtual HRESULT __stdcall get_Chart (
        /*[out,retval]*/ struct Chart * * Chart ) = 0;
      virtual HRESULT __stdcall get_ShapeStyle (
        /*[out,retval]*/ enum Office::MsoShapeStyleIndex * ShapeStyle ) = 0;
      virtual HRESULT __stdcall put_ShapeStyle (
        /*[in]*/ enum Office::MsoShapeStyleIndex ShapeStyle ) = 0;
      virtual HRESULT __stdcall get_BackgroundStyle (
        /*[out,retval]*/ enum Office::MsoBackgroundStyleIndex * BackgroundStyle ) = 0;
      virtual HRESULT __stdcall put_BackgroundStyle (
        /*[in]*/ enum Office::MsoBackgroundStyleIndex BackgroundStyle ) = 0;
      virtual HRESULT __stdcall get_SoftEdge (
        /*[out,retval]*/ struct Office::SoftEdgeFormat * * SoftEdge ) = 0;
      virtual HRESULT __stdcall get_Glow (
        /*[out,retval]*/ struct Office::GlowFormat * * Glow ) = 0;
      virtual HRESULT __stdcall get_Reflection (
        /*[out,retval]*/ struct Office::ReflectionFormat * * Reflection ) = 0;
      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * Title ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR Title ) = 0;
      virtual HRESULT __stdcall get_HasTable (
        /*[out,retval]*/ enum Office::MsoTriState * pHasTable ) = 0;
      virtual HRESULT __stdcall get_Table (
        /*[out,retval]*/ struct ReportTable * * Table ) = 0;
};

struct __declspec(uuid("c6984804-2c4d-4874-b69f-c14bf97c0bf1"))
Shapes : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Shape * * Item ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Shape * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall AddCallout (
        /*[in]*/ enum Office::MsoCalloutType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Callout ) = 0;
      virtual HRESULT __stdcall AddConnector (
        /*[in]*/ enum Office::MsoConnectorType Type,
        /*[in]*/ float BeginX,
        /*[in]*/ float BeginY,
        /*[in]*/ float EndX,
        /*[in]*/ float EndY,
        /*[out,retval]*/ struct Shape * * Connector ) = 0;
      virtual HRESULT __stdcall AddCurve (
        /*[in]*/ VARIANT SafeArrayOfPoints,
        /*[out,retval]*/ struct Shape * * Curve ) = 0;
      virtual HRESULT __stdcall AddLabel (
        /*[in]*/ enum Office::MsoTextOrientation Orientation,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Label ) = 0;
      virtual HRESULT __stdcall AddLine (
        /*[in]*/ float BeginX,
        /*[in]*/ float BeginY,
        /*[in]*/ float EndX,
        /*[in]*/ float EndY,
        /*[out,retval]*/ struct Shape * * Line ) = 0;
      virtual HRESULT __stdcall AddPicture (
        /*[in]*/ BSTR Filename,
        /*[in]*/ enum Office::MsoTriState LinkToFile,
        /*[in]*/ enum Office::MsoTriState SaveWithDocument,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Picture ) = 0;
      virtual HRESULT __stdcall AddPolyline (
        /*[in]*/ VARIANT SafeArrayOfPoints,
        /*[out,retval]*/ struct Shape * * Polyline ) = 0;
      virtual HRESULT __stdcall AddShape (
        /*[in]*/ enum Office::MsoAutoShapeType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Shape ) = 0;
      virtual HRESULT __stdcall AddTextEffect (
        /*[in]*/ enum Office::MsoPresetTextEffect PresetTextEffect,
        /*[in]*/ BSTR Text,
        /*[in]*/ BSTR FontName,
        /*[in]*/ float FontSize,
        /*[in]*/ enum Office::MsoTriState FontBold,
        /*[in]*/ enum Office::MsoTriState FontItalic,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[out,retval]*/ struct Shape * * TextEffect ) = 0;
      virtual HRESULT __stdcall AddTextbox (
        /*[in]*/ enum Office::MsoTextOrientation Orientation,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Textbox ) = 0;
      virtual HRESULT __stdcall BuildFreeform (
        /*[in]*/ enum Office::MsoEditingType EditingType,
        /*[in]*/ float X1,
        /*[in]*/ float Y1,
        /*[out,retval]*/ struct Office::FreeformBuilder * * FreeformBuilder ) = 0;
      virtual HRESULT __stdcall Range (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct ShapeRange * * Range ) = 0;
      virtual HRESULT __stdcall SelectAll ( ) = 0;
      virtual HRESULT __stdcall get_Background (
        /*[out,retval]*/ struct Shape * * Background ) = 0;
      virtual HRESULT __stdcall get_Default (
        /*[out,retval]*/ struct Shape * * Default ) = 0;
      virtual HRESULT __stdcall AddChart (
        /*[in]*/ int Style,
        /*[in]*/ enum Office::XlChartType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[in]*/ VARIANT_BOOL NewLayout,
        /*[out,retval]*/ struct Shape * * Chart ) = 0;
      virtual HRESULT __stdcall AddTable (
        /*[in]*/ int NumRows,
        /*[in]*/ int NumColumns,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Table ) = 0;
};

struct __declspec(uuid("ca6893a3-e8b7-46ed-89ab-0600354cbd7b"))
Chart : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall put_HasTitle (
        /*[in]*/ VARIANT_BOOL fTitle ) = 0;
      virtual HRESULT __stdcall get_HasTitle (
        /*[out,retval]*/ VARIANT_BOOL * fTitle ) = 0;
      virtual HRESULT __stdcall get_ChartTitle (
        /*[out,retval]*/ struct Office::IMsoChartTitle * * pval ) = 0;
      virtual HRESULT __stdcall get_DepthPercent (
        /*[out,retval]*/ int * pwDepthPercent ) = 0;
      virtual HRESULT __stdcall put_DepthPercent (
        /*[in]*/ int pwDepthPercent ) = 0;
      virtual HRESULT __stdcall get_Elevation (
        /*[out,retval]*/ int * pwElevation ) = 0;
      virtual HRESULT __stdcall put_Elevation (
        /*[in]*/ int pwElevation ) = 0;
      virtual HRESULT __stdcall get_GapDepth (
        /*[out,retval]*/ int * pwGapDepth ) = 0;
      virtual HRESULT __stdcall put_GapDepth (
        /*[in]*/ int pwGapDepth ) = 0;
      virtual HRESULT __stdcall get_HeightPercent (
        /*[out,retval]*/ int * pwHeightPercent ) = 0;
      virtual HRESULT __stdcall put_HeightPercent (
        /*[in]*/ int pwHeightPercent ) = 0;
      virtual HRESULT __stdcall get_Perspective (
        /*[out,retval]*/ int * pwPerspective ) = 0;
      virtual HRESULT __stdcall put_Perspective (
        /*[in]*/ int pwPerspective ) = 0;
      virtual HRESULT __stdcall get_RightAngleAxes (
        /*[out,retval]*/ VARIANT * pvarRightAngleAxes ) = 0;
      virtual HRESULT __stdcall put_RightAngleAxes (
        /*[in]*/ VARIANT pvarRightAngleAxes ) = 0;
      virtual HRESULT __stdcall get_Rotation (
        /*[out,retval]*/ VARIANT * pvarRotation ) = 0;
      virtual HRESULT __stdcall put_Rotation (
        /*[in]*/ VARIANT pvarRotation ) = 0;
      virtual HRESULT __stdcall put_DisplayBlanksAs (
        /*[in]*/ enum Office::XlDisplayBlanksAs pres ) = 0;
      virtual HRESULT __stdcall get_DisplayBlanksAs (
        /*[out,retval]*/ enum Office::XlDisplayBlanksAs * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectData (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectData (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectFormatting (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectFormatting (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectGoalSeek (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectGoalSeek (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectSelection (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectSelection (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectChartObjects (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectChartObjects (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall UnProtect (
        /*[in]*/ VARIANT Password = vtMissing ) = 0;
      virtual HRESULT __stdcall Protect (
        /*[in]*/ VARIANT Password = vtMissing,
        /*[in]*/ VARIANT DrawingObjects = vtMissing,
        /*[in]*/ VARIANT Contents = vtMissing,
        /*[in]*/ VARIANT Scenarios = vtMissing,
        /*[in]*/ VARIANT UserInterfaceOnly = vtMissing ) = 0;
      virtual HRESULT __stdcall get_ChartGroups (
        /*[in]*/ VARIANT * pvarIndex,
        /*[in]*/ VARIANT varIgallery,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall SeriesCollection (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall _ApplyDataLabels (
        /*[in]*/ enum Office::XlDataLabelsType Type,
        /*[in]*/ VARIANT IMsoLegendKey = vtMissing,
        /*[in]*/ VARIANT AutoText = vtMissing,
        /*[in]*/ VARIANT HasLeaderLines = vtMissing ) = 0;
      virtual HRESULT __stdcall get_SubType (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_SubType (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_Corners (
        /*[out,retval]*/ struct Office::IMsoCorners * * RHS ) = 0;
      virtual HRESULT __stdcall ApplyDataLabels (
        /*[in]*/ enum Office::XlDataLabelsType Type,
        /*[in]*/ VARIANT IMsoLegendKey = vtMissing,
        /*[in]*/ VARIANT AutoText = vtMissing,
        /*[in]*/ VARIANT HasLeaderLines = vtMissing,
        /*[in]*/ VARIANT ShowSeriesName = vtMissing,
        /*[in]*/ VARIANT ShowCategoryName = vtMissing,
        /*[in]*/ VARIANT ShowValue = vtMissing,
        /*[in]*/ VARIANT ShowPercentage = vtMissing,
        /*[in]*/ VARIANT ShowBubbleSize = vtMissing,
        /*[in]*/ VARIANT Separator = vtMissing ) = 0;
      virtual HRESULT __stdcall get_ChartType (
        /*[out,retval]*/ enum Office::XlChartType * RHS ) = 0;
      virtual HRESULT __stdcall put_ChartType (
        /*[in]*/ enum Office::XlChartType RHS ) = 0;
      virtual HRESULT __stdcall get_HasDataTable (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasDataTable (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall ApplyCustomType (
        /*[in]*/ enum Office::XlChartType ChartType,
        /*[in]*/ VARIANT TypeName = vtMissing ) = 0;
      virtual HRESULT __stdcall GetChartElement (
        /*[in]*/ long x,
        /*[in]*/ long y,
        /*[in,out]*/ long * ElementID,
        /*[in,out]*/ long * Arg1,
        /*[in,out]*/ long * Arg2 ) = 0;
      virtual HRESULT __stdcall SetSourceData (
        /*[in]*/ BSTR Source,
        /*[in]*/ VARIANT PlotBy = vtMissing ) = 0;
      virtual HRESULT __stdcall get_PlotBy (
        /*[out,retval]*/ enum Office::XlRowCol * PlotBy ) = 0;
      virtual HRESULT __stdcall put_PlotBy (
        /*[in]*/ enum Office::XlRowCol PlotBy ) = 0;
      virtual HRESULT __stdcall get_HasLegend (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasLegend (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Legend (
        /*[out,retval]*/ struct Office::IMsoLegend * * RHS ) = 0;
      virtual HRESULT __stdcall Axes (
        /*[in]*/ VARIANT Type,
        /*[in]*/ enum Office::XlAxisGroup AxisGroup,
        /*[out,retval]*/ IDispatch * * ppAxes ) = 0;
      virtual HRESULT __stdcall put_HasAxis (
        /*[in]*/ VARIANT axisType,
        /*[in]*/ VARIANT AxisGroup = vtMissing,
        /*[in]*/ VARIANT pval = vtMissing ) = 0;
      virtual HRESULT __stdcall get_HasAxis (
        /*[in]*/ VARIANT axisType,
        /*[in]*/ VARIANT AxisGroup,
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_Walls (
        /*[in]*/ VARIANT_BOOL fBackWall,
        /*[out,retval]*/ struct Office::IMsoWalls * * ppwalls ) = 0;
      virtual HRESULT __stdcall get_Floor (
        /*[out,retval]*/ struct Office::IMsoFloor * * ppfloor ) = 0;
      virtual HRESULT __stdcall get_PlotArea (
        /*[out,retval]*/ struct Office::IMsoPlotArea * * ppplotarea ) = 0;
      virtual HRESULT __stdcall get_PlotVisibleOnly (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_PlotVisibleOnly (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ChartArea (
        /*[out,retval]*/ struct Office::IMsoChartArea * * ppchartarea ) = 0;
      virtual HRESULT __stdcall AutoFormat (
        /*[in]*/ long rGallery,
        /*[in]*/ VARIANT varFormat = vtMissing ) = 0;
      virtual HRESULT __stdcall get_AutoScaling (
        /*[out,retval]*/ VARIANT_BOOL * f ) = 0;
      virtual HRESULT __stdcall put_AutoScaling (
        /*[in]*/ VARIANT_BOOL f ) = 0;
      virtual HRESULT __stdcall SetBackgroundPicture (
        /*[in]*/ BSTR bstr ) = 0;
      virtual HRESULT __stdcall ChartWizard (
        /*[in]*/ VARIANT varSource = vtMissing,
        /*[in]*/ VARIANT varGallery = vtMissing,
        /*[in]*/ VARIANT varFormat = vtMissing,
        /*[in]*/ VARIANT varPlotBy = vtMissing,
        /*[in]*/ VARIANT varCategoryLabels = vtMissing,
        /*[in]*/ VARIANT varSeriesLabels = vtMissing,
        /*[in]*/ VARIANT varHasLegend = vtMissing,
        /*[in]*/ VARIANT varTitle = vtMissing,
        /*[in]*/ VARIANT varCategoryTitle = vtMissing,
        /*[in]*/ VARIANT varValueTitle = vtMissing,
        /*[in]*/ VARIANT varExtraTitle = vtMissing,
        /*[in,lcid]*/ long LocaleID = 0 ) = 0;
      virtual HRESULT __stdcall CopyPicture (
        /*[in]*/ int Appearance,
        /*[in]*/ int Format,
        /*[in]*/ int Size,
        /*[in,lcid]*/ long LocaleID = 0 ) = 0;
      virtual HRESULT __stdcall get_DataTable (
        /*[out,retval]*/ struct Office::IMsoDataTable * * RHS ) = 0;
      virtual HRESULT __stdcall Evaluate (
        /*[in]*/ VARIANT varName,
        /*[in]*/ long LocaleID,
        /*[out]*/ long * ObjType,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall _Evaluate (
        /*[in]*/ VARIANT varName,
        /*[in]*/ long LocaleID,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall Paste (
        /*[in]*/ VARIANT varType = vtMissing,
        /*[in,lcid]*/ long LocaleID = 0 ) = 0;
      virtual HRESULT __stdcall get_BarShape (
        /*[out,retval]*/ enum Office::XlBarShape * pShape ) = 0;
      virtual HRESULT __stdcall put_BarShape (
        /*[in]*/ enum Office::XlBarShape pShape ) = 0;
      virtual HRESULT __stdcall Export (
        /*[in]*/ BSTR bstr,
        /*[in]*/ VARIANT varFilterName,
        /*[in]*/ VARIANT varInteractive,
        /*[out,retval]*/ VARIANT_BOOL * f ) = 0;
      virtual HRESULT __stdcall SetDefaultChart (
        /*[in]*/ VARIANT varName ) = 0;
      virtual HRESULT __stdcall ApplyChartTemplate (
        /*[in]*/ BSTR bstrFileName ) = 0;
      virtual HRESULT __stdcall SaveChartTemplate (
        /*[in]*/ BSTR bstrFileName ) = 0;
      virtual HRESULT __stdcall get_SideWall (
        /*[out,retval]*/ struct Office::IMsoWalls * * RHS ) = 0;
      virtual HRESULT __stdcall get_BackWall (
        /*[out,retval]*/ struct Office::IMsoWalls * * RHS ) = 0;
      virtual HRESULT __stdcall get_ChartStyle (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_ChartStyle (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall ClearToMatchStyle ( ) = 0;
      virtual HRESULT __stdcall get_PivotLayout (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_HasPivotFields (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasPivotFields (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall RefreshPivotTable ( ) = 0;
      virtual HRESULT __stdcall put_ShowDataLabelsOverMaximum (
        /*[in]*/ VARIANT_BOOL pRHS ) = 0;
      virtual HRESULT __stdcall get_ShowDataLabelsOverMaximum (
        /*[out,retval]*/ VARIANT_BOOL * pRHS ) = 0;
      virtual HRESULT __stdcall ApplyLayout (
        /*[in]*/ long Layout,
        /*[in]*/ VARIANT varChartType = vtMissing ) = 0;
      virtual HRESULT __stdcall get_Selection (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Refresh ( ) = 0;
      virtual HRESULT __stdcall SetElement (
        /*[in]*/ enum Office::MsoChartElementType RHS ) = 0;
      virtual HRESULT __stdcall get_ChartData (
        /*[out,retval]*/ struct Office::IMsoChartData * * ppchartdata ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct Office::IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Shapes (
        /*[out,retval]*/ struct Shapes * * ppShapes ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Area3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct Office::IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall AreaGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Bar3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct Office::IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall BarGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Column3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct Office::IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall ColumnGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Line3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct Office::IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall LineGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Pie3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct Office::IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall PieGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall DoughnutGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall RadarGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_SurfaceGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct Office::IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall XYGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[in]*/ VARIANT Replace,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_ShowReportFilterFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowReportFilterFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall get_ShowLegendFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowLegendFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall get_ShowAxisFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowAxisFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall get_ShowValueFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowValueFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall get_ShowAllFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowAllFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall UpdateChartData (
        /*[in]*/ VARIANT_BOOL Task,
        /*[in]*/ VARIANT_BOOL Timephased,
        /*[in]*/ BSTR GroupName,
        /*[in]*/ BSTR FilterName,
        /*[in]*/ enum PjField LabelField,
        /*[in]*/ int OutlineLevel,
        /*[in]*/ VARIANT SafeArrayOfPjField,
        /*[in]*/ VARIANT SafeArrayOfPjTimescaledData,
        /*[in]*/ enum PjTimescaleUnit TimeScaleUnit,
        /*[in]*/ int TimescaleUnitCount,
        /*[in]*/ VARIANT StartDate = vtMissing,
        /*[in]*/ VARIANT FinishDate = vtMissing ) = 0;
      virtual HRESULT __stdcall get_ChartColor (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_ChartColor (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall ClearToMatchColorStyle ( ) = 0;
};

struct __declspec(uuid("f7f947d7-dda9-47cb-842e-7de3927f1a68"))
ShapeRange : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct _MSProject * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Shape * * Item ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Shape * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Align (
        /*[in]*/ enum Office::MsoAlignCmd AlignCmd,
        /*[in]*/ enum Office::MsoTriState RelativeTo ) = 0;
      virtual HRESULT __stdcall Apply ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Distribute (
        /*[in]*/ enum Office::MsoDistributeCmd DistributeCmd,
        /*[in]*/ enum Office::MsoTriState RelativeTo ) = 0;
      virtual HRESULT __stdcall Duplicate (
        /*[out,retval]*/ struct ShapeRange * * Duplicate ) = 0;
      virtual HRESULT __stdcall Flip (
        /*[in]*/ enum Office::MsoFlipCmd FlipCmd ) = 0;
      virtual HRESULT __stdcall IncrementLeft (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementRotation (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementTop (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall Group (
        /*[out,retval]*/ struct Shape * * Group ) = 0;
      virtual HRESULT __stdcall PickUp ( ) = 0;
      virtual HRESULT __stdcall Regroup (
        /*[out,retval]*/ struct Shape * * Regroup ) = 0;
      virtual HRESULT __stdcall RerouteConnections ( ) = 0;
      virtual HRESULT __stdcall ScaleHeight (
        /*[in]*/ float Factor,
        /*[in]*/ enum Office::MsoTriState RelativeToOriginalSize,
        /*[in]*/ enum Office::MsoScaleFrom fScale ) = 0;
      virtual HRESULT __stdcall ScaleWidth (
        /*[in]*/ float Factor,
        /*[in]*/ enum Office::MsoTriState RelativeToOriginalSize,
        /*[in]*/ enum Office::MsoScaleFrom fScale ) = 0;
      virtual HRESULT __stdcall Select (
        /*[in]*/ VARIANT Replace = vtMissing ) = 0;
      virtual HRESULT __stdcall SetShapesDefaultProperties ( ) = 0;
      virtual HRESULT __stdcall Ungroup (
        /*[out,retval]*/ struct ShapeRange * * Ungroup ) = 0;
      virtual HRESULT __stdcall ZOrder (
        /*[in]*/ enum Office::MsoZOrderCmd ZOrderCmd ) = 0;
      virtual HRESULT __stdcall get_Adjustments (
        /*[out,retval]*/ struct Office::TangramAdjustments * * Adjustments ) = 0;
      virtual HRESULT __stdcall get_AutoShapeType (
        /*[out,retval]*/ enum Office::MsoAutoShapeType * AutoShapeType ) = 0;
      virtual HRESULT __stdcall put_AutoShapeType (
        /*[in]*/ enum Office::MsoAutoShapeType AutoShapeType ) = 0;
      virtual HRESULT __stdcall get_BlackWhiteMode (
        /*[out,retval]*/ enum Office::MsoBlackWhiteMode * BlackWhiteMode ) = 0;
      virtual HRESULT __stdcall put_BlackWhiteMode (
        /*[in]*/ enum Office::MsoBlackWhiteMode BlackWhiteMode ) = 0;
      virtual HRESULT __stdcall get_Callout (
        /*[out,retval]*/ struct Office::CalloutFormat * * Callout ) = 0;
      virtual HRESULT __stdcall get_ConnectionSiteCount (
        /*[out,retval]*/ int * ConnectionSiteCount ) = 0;
      virtual HRESULT __stdcall get_Connector (
        /*[out,retval]*/ enum Office::MsoTriState * Connector ) = 0;
      virtual HRESULT __stdcall get_ConnectorFormat (
        /*[out,retval]*/ struct Office::ConnectorFormat * * ConnectorFormat ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct Office::FillFormat * * Fill ) = 0;
      virtual HRESULT __stdcall get_GroupItems (
        /*[out,retval]*/ struct Office::GroupShapes * * GroupItems ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ float * Height ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ float Height ) = 0;
      virtual HRESULT __stdcall get_HorizontalFlip (
        /*[out,retval]*/ enum Office::MsoTriState * HorizontalFlip ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ float * Left ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ float Left ) = 0;
      virtual HRESULT __stdcall get_Line (
        /*[out,retval]*/ struct Office::LineFormat * * Line ) = 0;
      virtual HRESULT __stdcall get_LockAspectRatio (
        /*[out,retval]*/ enum Office::MsoTriState * LockAspectRatio ) = 0;
      virtual HRESULT __stdcall put_LockAspectRatio (
        /*[in]*/ enum Office::MsoTriState LockAspectRatio ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Nodes (
        /*[out,retval]*/ struct Office::ShapeNodes * * Nodes ) = 0;
      virtual HRESULT __stdcall get_Rotation (
        /*[out,retval]*/ float * Rotation ) = 0;
      virtual HRESULT __stdcall put_Rotation (
        /*[in]*/ float Rotation ) = 0;
      virtual HRESULT __stdcall get_PictureFormat (
        /*[out,retval]*/ struct Office::PictureFormat * * Picture ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ struct Office::ShadowFormat * * Shadow ) = 0;
      virtual HRESULT __stdcall get_TextEffect (
        /*[out,retval]*/ struct Office::TextEffectFormat * * TextEffect ) = 0;
      virtual HRESULT __stdcall get_TextFrame (
        /*[out,retval]*/ struct Office::TextFrame * * TextFrame ) = 0;
      virtual HRESULT __stdcall get_ThreeD (
        /*[out,retval]*/ struct Office::ThreeDFormat * * ThreeD ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ float * Top ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ float Top ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum Office::MsoShapeType * Type ) = 0;
      virtual HRESULT __stdcall get_VerticalFlip (
        /*[out,retval]*/ enum Office::MsoTriState * VerticalFlip ) = 0;
      virtual HRESULT __stdcall get_Vertices (
        /*[out,retval]*/ VARIANT * Vertices ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum Office::MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum Office::MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ float * Width ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ float Width ) = 0;
      virtual HRESULT __stdcall get_ZOrderPosition (
        /*[out,retval]*/ int * ZOrderPosition ) = 0;
      virtual HRESULT __stdcall get_Script (
        /*[out,retval]*/ struct Office::Script * * Script ) = 0;
      virtual HRESULT __stdcall get_AlternativeText (
        /*[out,retval]*/ BSTR * AlternativeText ) = 0;
      virtual HRESULT __stdcall put_AlternativeText (
        /*[in]*/ BSTR AlternativeText ) = 0;
      virtual HRESULT __stdcall get_Child (
        /*[out,retval]*/ enum Office::MsoTriState * Child ) = 0;
      virtual HRESULT __stdcall get_ParentGroup (
        /*[out,retval]*/ struct Shape * * Parent ) = 0;
      virtual HRESULT __stdcall get_CanvasItems (
        /*[out,retval]*/ struct Office::CanvasShapes * * CanvasShapes ) = 0;
      virtual HRESULT __stdcall get_ID (
        /*[out,retval]*/ int * pid ) = 0;
      virtual HRESULT __stdcall CanvasCropLeft (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropTop (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropRight (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropBottom (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall put_RTF (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_TextFrame2 (
        /*[out,retval]*/ struct Office::TextFrame2 * * Frame ) = 0;
      virtual HRESULT __stdcall Cut ( ) = 0;
      virtual HRESULT __stdcall Copy ( ) = 0;
      virtual HRESULT __stdcall get_HasChart (
        /*[out,retval]*/ enum Office::MsoTriState * pHasChart ) = 0;
      virtual HRESULT __stdcall get_Chart (
        /*[out,retval]*/ struct Chart * * Chart ) = 0;
      virtual HRESULT __stdcall get_ShapeStyle (
        /*[out,retval]*/ enum Office::MsoShapeStyleIndex * ShapeStyle ) = 0;
      virtual HRESULT __stdcall put_ShapeStyle (
        /*[in]*/ enum Office::MsoShapeStyleIndex ShapeStyle ) = 0;
      virtual HRESULT __stdcall get_BackgroundStyle (
        /*[out,retval]*/ enum Office::MsoBackgroundStyleIndex * BackgroundStyle ) = 0;
      virtual HRESULT __stdcall put_BackgroundStyle (
        /*[in]*/ enum Office::MsoBackgroundStyleIndex BackgroundStyle ) = 0;
      virtual HRESULT __stdcall get_SoftEdge (
        /*[out,retval]*/ struct Office::SoftEdgeFormat * * SoftEdge ) = 0;
      virtual HRESULT __stdcall get_Glow (
        /*[out,retval]*/ struct Office::GlowFormat * * Glow ) = 0;
      virtual HRESULT __stdcall get_Reflection (
        /*[out,retval]*/ struct Office::ReflectionFormat * * Reflection ) = 0;
      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * Title ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR Title ) = 0;
      virtual HRESULT __stdcall MergeShapes (
        /*[in]*/ enum Office::MsoMergeCmd MergeCmd,
        /*[in]*/ struct Shape * PrimaryShape ) = 0;
      virtual HRESULT __stdcall get_HasTable (
        /*[out,retval]*/ enum Office::MsoTriState * pHasTable ) = 0;
      virtual HRESULT __stdcall get_Table (
        /*[out,retval]*/ struct ReportTable * * Table ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_MSProject =
    {0xa7107640,0x94df,0x1068,{0x85,0x5e,0x00,0xdd,0x01,0x07,0x54,0x45}};
extern "C" const GUID __declspec(selectany) DIID_List =
    {0x00020b17,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID_Selection =
    {0x00020b18,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID_Cell =
    {0x00020b19,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID_Pane =
    {0x00020b04,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID_Window =
    {0x00020b02,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID_Windows =
    {0x00020b03,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__IProjectDoc =
    {0x00020b00,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__EProjectDoc =
    {0xf81dd3c0,0x5089,0x11cf,{0xa4,0x9d,0x00,0xaa,0x00,0x57,0x4c,0x74}};
extern "C" const GUID __declspec(selectany) CLSID_Project =
    {0x1019a320,0x508a,0x11cf,{0xa4,0x9d,0x00,0xaa,0x00,0x57,0x4c,0x74}};
extern "C" const GUID __declspec(selectany) DIID_Projects =
    {0x00020b01,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__Global =
    {0x78e9f620,0xebc0,0x11cf,{0xa5,0x23,0x00,0xa0,0xc9,0x04,0xde,0x55}};
extern "C" const GUID __declspec(selectany) DIID__MSProject =
    {0x00020aff,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__EProjectApp =
    {0x7b7597d0,0x0c9f,0x11d0,{0x8c,0x43,0x00,0xa0,0xc9,0x04,0xdc,0xd4}};
extern "C" const GUID __declspec(selectany) CLSID_Application =
    {0x36d27c48,0xa1e8,0x11d3,{0xba,0x55,0x00,0xc0,0x4f,0x72,0xf3,0x25}};
extern "C" const GUID __declspec(selectany) IID_Shift =
    {0x000c0c50,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TimeScaleValue =
    {0x000c0c54,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TimeScaleValues =
    {0x000c0c53,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SplitPart =
    {0x000c0c48,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SplitParts =
    {0x000c0c47,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_Global =
    {0x7742af30,0xebc0,0x11cf,{0xa5,0x23,0x00,0xa0,0xc9,0x04,0xde,0x55}};
extern "C" const GUID __declspec(selectany) IID_View =
    {0x103ef3dc,0x9fce,0x4611,{0x8c,0x8b,0xf3,0x06,0xc8,0x88,0x1c,0xa5}};
extern "C" const GUID __declspec(selectany) IID_Views =
    {0x4cf32482,0x106b,0x4fff,{0xa1,0xab,0x7d,0xd3,0x95,0xfb,0x09,0x58}};
extern "C" const GUID __declspec(selectany) IID_Filter =
    {0xdc2fddaf,0xce01,0x42dc,{0xbb,0x4f,0xb3,0xfb,0x33,0x46,0xd5,0xb7}};
extern "C" const GUID __declspec(selectany) IID_Filters =
    {0xed989e98,0xf561,0x4d58,{0x8f,0x67,0x5d,0x2e,0x2b,0x92,0x0e,0x77}};
extern "C" const GUID __declspec(selectany) IID_EventInfo =
    {0x02497005,0x3861,0x4603,{0x80,0xa4,0xff,0x30,0x96,0x31,0xdb,0xa1}};
extern "C" const GUID __declspec(selectany) IID_Profile =
    {0x6711f81e,0xaa55,0x47ee,{0xaa,0x9f,0x31,0xb0,0x0e,0x70,0x9c,0xb6}};
extern "C" const GUID __declspec(selectany) IID_Profiles =
    {0x08cd6de7,0x87cd,0x42ab,{0xbd,0x28,0x6e,0x2c,0x01,0x70,0xa2,0x74}};
extern "C" const GUID __declspec(selectany) DIID__EProjectApp2 =
    {0x5066d7c4,0x1ed7,0x48c4,{0xac,0xe7,0x29,0x9e,0x10,0x9d,0x36,0x8c}};
extern "C" const GUID __declspec(selectany) DIID_Windows2 =
    {0x00020b05,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ReportTemplate =
    {0x46bff766,0xf07a,0x409c,{0xa8,0x5f,0xee,0xd0,0xa3,0x65,0x89,0xf9}};
extern "C" const GUID __declspec(selectany) IID_ReportTemplates =
    {0x5918f188,0x19be,0x401e,{0xa7,0x02,0xfe,0xe2,0x68,0x80,0x47,0x38}};
extern "C" const GUID __declspec(selectany) IID_ReportTable =
    {0x33daa9fa,0x94ca,0x414e,{0xbc,0xf4,0x3e,0x26,0x0b,0x02,0xb5,0x5e}};
extern "C" const GUID __declspec(selectany) IID_Series =
    {0xda4986e8,0xff38,0x4c85,{0x88,0x1a,0x78,0xf7,0x9f,0x14,0x36,0xd9}};
//extern "C" const GUID __declspec(selectany) IID_SeriesCollection =
//    {0x787fbde2,0xe363,0x48aa,{0x94,0xe1,0xfb,0x94,0x47,0x47,0x70,0xb7}};
extern "C" const GUID __declspec(selectany) IID_Task =
    {0x000c0c3f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Subproject =
    {0x00020b1c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Subprojects =
    {0x00020b1b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TaskDependency =
    {0xa7c6acb0,0x58c6,0x11d2,{0xae,0x5a,0x00,0xc0,0x4f,0xb6,0xf7,0x01}};
extern "C" const GUID __declspec(selectany) IID_TaskDependencies =
    {0xa7c6acb1,0x58c6,0x11d2,{0xae,0x5a,0x00,0xc0,0x4f,0xb6,0xf7,0x01}};
extern "C" const GUID __declspec(selectany) IID_Tasks =
    {0x000c0c40,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PredecessorDrivers =
    {0x9dd14143,0xf0a9,0x4692,{0x82,0x88,0xa6,0x83,0x5f,0x93,0xdc,0x8a}};
extern "C" const GUID __declspec(selectany) IID_ChildDrivers =
    {0x9dd14144,0xf0a9,0x4692,{0x82,0x88,0xa6,0x83,0x5f,0x93,0xdc,0x8a}};
extern "C" const GUID __declspec(selectany) IID_Resource =
    {0x000c0c41,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Assignment =
    {0x000c0c45,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PayRate =
    {0x000c0c58,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PayRates =
    {0x000c0c57,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CostRateTable =
    {0x000c0c56,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CostRateTables =
    {0x000c0c55,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Availability =
    {0x1251566d,0x2bdf,0x11d2,{0x9e,0xac,0x00,0xc0,0x4f,0xb9,0x2e,0x6f}};
extern "C" const GUID __declspec(selectany) IID_Availabilities =
    {0x1251566c,0x2bdf,0x11d2,{0x9e,0xac,0x00,0xc0,0x4f,0xb9,0x2e,0x6f}};
extern "C" const GUID __declspec(selectany) IID_Resources =
    {0x000c0c42,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Assignments =
    {0x000c0c46,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ActualStartDrivers =
    {0x9dd14142,0xf0a9,0x4692,{0x82,0x88,0xa6,0x83,0x5f,0x93,0xdc,0x8a}};
extern "C" const GUID __declspec(selectany) IID_CalendarDrivers =
    {0x9dd14145,0xf0a9,0x4692,{0x82,0x88,0xa6,0x83,0x5f,0x93,0xdc,0x8a}};
extern "C" const GUID __declspec(selectany) IID_OverAllocatedAssignments =
    {0x9dd14146,0xf0a9,0x4692,{0x82,0x88,0xa6,0x83,0x5f,0x93,0xdc,0x8a}};
extern "C" const GUID __declspec(selectany) IID_StartDriver =
    {0x9dd14141,0xf0a9,0x4692,{0x82,0x88,0xa6,0x83,0x5f,0x93,0xdc,0x8a}};
extern "C" const GUID __declspec(selectany) IID_Calendar =
    {0x000c0c43,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WeekDay =
    {0x000c0c4f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WeekDays =
    {0x000c0c4e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Period =
    {0x000c0c49,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Calendars =
    {0x000c0c44,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Exception =
    {0x936f4d59,0x007b,0x4f7b,{0x89,0x32,0x90,0xa4,0x0f,0xc4,0x43,0x91}};
extern "C" const GUID __declspec(selectany) IID_Exceptions =
    {0x9dbaec97,0xada1,0x4488,{0x88,0x45,0x81,0x8e,0x73,0x4f,0x18,0x2e}};
extern "C" const GUID __declspec(selectany) IID_Years =
    {0x000c0c4a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Months =
    {0x000c0c4c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Year =
    {0x000c0c4b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Days =
    {0x000c0c51,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Month =
    {0x000c0c4d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Day =
    {0x000c0c52,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TaskGroups =
    {0x11589054,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_ResourceGroups =
    {0x11589055,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_Group =
    {0x11589051,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_GroupCriterion =
    {0x11589053,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_GroupCriteria =
    {0x11589052,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_Groups =
    {0x11589050,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_ViewsSingle =
    {0xb4097887,0xec12,0x4683,{0x96,0x22,0x99,0x74,0xef,0x26,0x35,0x3c}};
extern "C" const GUID __declspec(selectany) IID_ViewsCombination =
    {0xce4f7d83,0x369b,0x43cf,{0x96,0xa8,0x29,0xc2,0xde,0x2b,0x86,0x58}};
extern "C" const GUID __declspec(selectany) IID_ViewSingle =
    {0xf15fde9e,0xfdc1,0x44d2,{0xa0,0xd0,0x24,0x9a,0xd4,0x8f,0x58,0xfe}};
extern "C" const GUID __declspec(selectany) IID_ViewCombination =
    {0x0880e27c,0xc621,0x4349,{0x96,0xad,0x56,0x52,0x0c,0x82,0x7e,0x14}};
extern "C" const GUID __declspec(selectany) IID_Tables =
    {0x31e3eb5a,0x6339,0x43b0,{0xb1,0xb8,0x1a,0xed,0x03,0x88,0x6a,0xec}};
extern "C" const GUID __declspec(selectany) IID_Table =
    {0x54eff41a,0x4603,0x4771,{0x80,0xee,0xf3,0x13,0xbf,0x9f,0xae,0xc2}};
extern "C" const GUID __declspec(selectany) IID_TableField =
    {0x747d4ba8,0xfb3b,0x4c2c,{0xb6,0x15,0x02,0xcb,0x6e,0xbf,0x0a,0xe7}};
extern "C" const GUID __declspec(selectany) IID_TableFields =
    {0xbf6d2103,0x92d3,0x4162,{0x98,0x16,0xa3,0xd8,0x11,0xbc,0xf8,0xca}};
extern "C" const GUID __declspec(selectany) IID_OutlineCode =
    {0x30dff087,0x4ddc,0x4166,{0x93,0xb2,0xa9,0xc2,0x59,0xc1,0xe4,0xad}};
extern "C" const GUID __declspec(selectany) IID_OutlineCodes =
    {0x4269779b,0xf035,0x4e2f,{0xab,0xdd,0x54,0xb6,0xd9,0x4a,0x2a,0x03}};
extern "C" const GUID __declspec(selectany) IID_LookupTableEntry =
    {0xc19e7deb,0xc19b,0x4294,{0xbc,0x60,0x5b,0x2d,0x99,0xc0,0x03,0x98}};
extern "C" const GUID __declspec(selectany) IID_LookupTable =
    {0xda33f25e,0xad36,0x48b9,{0x9c,0xb6,0xcd,0xb0,0xcf,0x6e,0xe0,0x70}};
extern "C" const GUID __declspec(selectany) IID_CodeMaskLevel =
    {0xe75e1380,0x8623,0x41c9,{0x99,0x20,0x50,0x8f,0x67,0x6c,0x45,0x75}};
extern "C" const GUID __declspec(selectany) IID_CodeMask =
    {0x4cc10f2b,0x7df1,0x413c,{0xa4,0x4d,0x9a,0xb3,0x5a,0xdf,0xd9,0xae}};
extern "C" const GUID __declspec(selectany) IID_WorkWeek =
    {0x22228b77,0xf739,0x46a2,{0xbf,0x45,0xee,0xe4,0x3a,0x93,0x6f,0x06}};
extern "C" const GUID __declspec(selectany) IID_WorkWeeks =
    {0x1137eff0,0x691f,0x4f78,{0x96,0x47,0x40,0xfe,0x8e,0x50,0x0d,0x34}};
extern "C" const GUID __declspec(selectany) IID_WorkWeekDay =
    {0x9bc789c9,0x50c6,0x476f,{0xa9,0x6c,0xd4,0x6e,0x95,0xb4,0xc9,0x01}};
extern "C" const GUID __declspec(selectany) IID_WorkWeekDays =
    {0x1f4f463f,0xeb4b,0x4d2e,{0x86,0xed,0x61,0xa9,0xcf,0xa4,0x1e,0x89}};
extern "C" const GUID __declspec(selectany) IID_TaskGroups2 =
    {0x1158905a,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_ResourceGroups2 =
    {0x1158905b,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_Group2 =
    {0x11589058,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_GroupCriterion2 =
    {0x11589057,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_GroupCriteria2 =
    {0x11589056,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_Groups2 =
    {0x11589059,0x69f0,0x11d2,{0xb8,0x89,0x00,0xc0,0x4f,0xb9,0x07,0x29}};
extern "C" const GUID __declspec(selectany) IID_Reports =
    {0xff59cfba,0xcb6f,0x4b92,{0xa7,0xd2,0x97,0xd1,0xca,0xb6,0xeb,0xff}};
extern "C" const GUID __declspec(selectany) IID_Report =
    {0xc4f74db0,0xe706,0x4ad5,{0x9e,0x71,0xad,0x5e,0x6a,0x0c,0xf3,0x88}};
//extern "C" const GUID __declspec(selectany) IID_Shape =
//    {0x7300bad0,0xc853,0x475e,{0x80,0xa7,0x2f,0xa3,0xa2,0x86,0xf9,0x1f}};
//extern "C" const GUID __declspec(selectany) IID_Shapes =
//    {0xc6984804,0x2c4d,0x4874,{0xb6,0x9f,0xc1,0x4b,0xf9,0x7c,0x0b,0xf1}};
extern "C" const GUID __declspec(selectany) IID_Chart =
    {0xca6893a3,0xe8b7,0x46ed,{0x89,0xab,0x06,0x00,0x35,0x4c,0xbd,0x7b}};
//extern "C" const GUID __declspec(selectany) IID_ShapeRange =
//    {0xf7f947d7,0xdda9,0x47cb,{0x84,0x2e,0x7d,0xe3,0x92,0x7f,0x1a,0x68}};

} // namespace MSProject

#pragma pack(pop)
