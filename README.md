# DragDropNormalizer

In Windows 10 version 22H2 Microsoft (intentionally?) broke the design of the overlay that appears while you dragging a file - it become solid-white with ugly corners, while it always has been translucent.

This little tool runs at startup for a few milliseconds without needing adminstrator rights and patches the style in-memory, returning the look that was present in older Windows versions, more specifically - in Windows 11 version 21H2.

The distribution which can be downloaded from [Releases](https://github.com/krlvm/DragDropNormalizer/releases) includes batch files, which can be used for automatic installation and registering for running at startup.

Use [ContextMenuNormalizer](https://github.com/krlvm/ContextMenuNormalizer) to make so-called *immersive* context menus, that is used in classic File Explorer (i.e. "Show more options") and the rest of classic menus look consistent.

Before:\
![Before](https://github.com/krlvm/DragDropNormalizer/blob/master/.screenshots/before.png?raw=true)

After:\
![After](https://github.com/krlvm/DragDropNormalizer/blob/master/.screenshots/after.png?raw=true)
