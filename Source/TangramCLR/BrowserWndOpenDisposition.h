#pragma once

public enum class Disposition
{
	UNKNOWN = 0x00000000,
	CURRENT_TAB = 0x00000001,
	// Indicates that only one tab with the url should exist in the same window.
	SINGLETON_TAB = 0x00000002,
	NEW_FOREGROUND_TAB = 0x00000003,
	NEW_BACKGROUND_TAB = 0x00000004,
	NEW_POPUP = 0x00000005,
	NEW_WINDOW = 0x00000006,
	SAVE_TO_DISK = 0x00000007,
	OFF_THE_RECORD = 0x00000008,
	IGNORE_ACTION = 0x00000009,
	// Activates an existing tab containing the url, rather than navigating.
	// This is similar to SINGLETON_TAB, but searches across all windows from
	// the current profile and anonymity (instead of just the current one);
	// closes the current tab on switching if the current tab was the NTP with
	// no session history; and behaves like CURRENT_TAB instead of
	// NEW_FOREGROUND_TAB when no existing tab is found.
	SWITCH_TO_TAB = 0x0000000a
	// Update when adding a new disposition.
};