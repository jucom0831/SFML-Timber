#pragma once

enum class SortingLayers
{
	Background,
	Foreground,
	UI,
	Default,
};

enum class SceneIds
{
	None = -1,
	Title,
	Dev2,
	Dev3,
	Select,
	ModSelect,
	Count,
};

enum class Origins
{
	// T M B
	// L C R
	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR,
	Custom,
};

enum class Sides
{
	Left,
	Right,
	None,
};