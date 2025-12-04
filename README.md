# Schedule Planner Program

**Created by:** James Truong for CS302 Winter 2023

**Program:** #3

---

## Overview

Welcome to the Schedule Planner Program!

This program helps manage events into a schedule using a tree-based data structure for efficient organization. The application supports three types of events—meetings, workshops, and conventions—each with unique characteristics. Events are organized in a binary search tree, making it easy to find and manage your busy schedule.

---

## How to Build and Run

To compile and update all files use the command:

```bash
make all
```

To run the Schedule Planner Program after `make all` enter:

```bash
./prog3
```

---

## Usage

This program uses a menu interface using integer inputs to navigate the menu. If non integer is entered or one that is not within range, it will prompt for another input.

### Menu Options

The menu options currently available for use are:

- **Add an event** - Create meetings, workshops, or conventions
- **Display all events** - View your scheduled events
- **Remove events** - Delete events from the schedule

Some special features have not yet been implemented.

---

## Event Types

The three events you can add are: **meeting**, **workshop**, and **convention**.

All of these events have names (title), a date, and a location. But there are unique differences between each event type. You can enter the date any way you prefer, but keep it consistent so it is easy for you to refer when you view it again!

### Meeting

A meeting has a **meeting topic**.

### Workshop

A workshop has a **capacity for participants** and an **instructor**.

### Convention

A convention has a **sponsor** and **admission price**.

These are the different information for those events you can input and display.

---

## Project Structure

- `prog3-main.cpp` - Client application entry point
- `prog3-menu.cpp/h` - Menu interface implementation
- `prog3-schedule.cpp/h` - Event classes (Meeting, Workshop, Convention)
- `prog3-table.cpp/h` - Binary search tree data structure
- `Makefile` - Build configuration
- `prog3-req.txt` - Assignment requirements and specifications

---

Happy planning!
