// -----------------------------------------------------------------------------
//  SolidDesignerCommands.h
//
//  AUTO-GENERATED FILE. DO NOT EDIT BY HAND.
//
//  Generated from: CommandsConfig.xml
// -----------------------------------------------------------------------------

#pragma once
#include <string_view>

namespace sdr
{
    namespace Cmd
    {
        // NOTE:
        //   - Each constant is a std::string_view to the command id as defined
        //     in CommandsConfig.xml.
        //   - Use these constants in ICommand::Id() implementations, Ribbon/Menu
        //     bindings, etc. Never hard-code string literals like "file.save".

        // === Category: analysis ===
        inline constexpr std::string_view ANALYSIS_BODYCHECK             = "analysis.bodyCheck"; // Body Check
        inline constexpr std::string_view ANALYSIS_INTERFERENCE          = "analysis.interference"; // Interference Check
        inline constexpr std::string_view ANALYSIS_MASS                  = "analysis.mass"; // Mass Analysis

        // === Category: application ===
        inline constexpr std::string_view APP_SWITCH_ASSEMBLY            = "app.switch.assembly"; // Assembly Design
        inline constexpr std::string_view APP_SWITCH_BIM                 = "app.switch.bim"; // BIM
        inline constexpr std::string_view APP_SWITCH_PARTMODELING        = "app.switch.partModeling"; // Part Modeling
        inline constexpr std::string_view APP_SWITCH_SHEETMETAL          = "app.switch.sheetMetal"; // Sheet Metal Design
        inline constexpr std::string_view APP_SWITCH_SHIP                = "app.switch.ship"; // Ship Design
        inline constexpr std::string_view APP_SWITCH_SKETCH              = "app.switch.sketch"; // Sketch Environment

        // === Category: assembly ===
        inline constexpr std::string_view ASM_ADDCOMPONENT               = "asm.addComponent"; // Add Component
        inline constexpr std::string_view ASM_ALIGN                      = "asm.align"; // Align
        inline constexpr std::string_view ASM_ARRANGE                    = "asm.arrange"; // Arrange Components
        inline constexpr std::string_view ASM_CONSTRAINT                 = "asm.constraint"; // Assembly Constraints
        inline constexpr std::string_view ASM_DISTANCE                   = "asm.distance"; // Distance
        inline constexpr std::string_view ASM_EXPLODE                    = "asm.explode"; // Exploded View
        inline constexpr std::string_view ASM_MATE                       = "asm.mate"; // Mate
        inline constexpr std::string_view ASM_NEWCOMPONENT               = "asm.newComponent"; // New Component
        inline constexpr std::string_view ASM_REPLACECOMPONENT           = "asm.replaceComponent"; // Replace Component
        inline constexpr std::string_view ASM_UNEXPLODE                  = "asm.unexplode"; // Collapse

        // === Category: boolean ===
        inline constexpr std::string_view MODEL_BOOLEAN_INTERSECT        = "model.boolean.intersect"; // Intersect
        inline constexpr std::string_view MODEL_BOOLEAN_SUBTRACT         = "model.boolean.subtract"; // Subtract
        inline constexpr std::string_view MODEL_BOOLEAN_UNION            = "model.boolean.union"; // Union

        // === Category: curve ===
        inline constexpr std::string_view CURVE_ARC                      = "curve.arc"; // Arc
        inline constexpr std::string_view CURVE_CIRCLE                   = "curve.circle"; // Circle
        inline constexpr std::string_view CURVE_EXTEND                   = "curve.extend"; // Extend Curve
        inline constexpr std::string_view CURVE_FILLET                   = "curve.fillet"; // Curve Fillet
        inline constexpr std::string_view CURVE_FITSPLINE                = "curve.fitSpline"; // Fit Spline
        inline constexpr std::string_view CURVE_JOIN                     = "curve.join"; // Join Curves
        inline constexpr std::string_view CURVE_LINE                     = "curve.line"; // Line
        inline constexpr std::string_view CURVE_OFFSET                   = "curve.offset"; // Offset Curve
        inline constexpr std::string_view CURVE_POINT                    = "curve.point"; // Point
        inline constexpr std::string_view CURVE_RECTANGLE                = "curve.rectangle"; // Rectangle
        inline constexpr std::string_view CURVE_SPLINETHROUGH            = "curve.splineThrough"; // Spline Through Points
        inline constexpr std::string_view CURVE_STUDIOSPLINE             = "curve.studioSpline"; // Studio Spline
        inline constexpr std::string_view CURVE_TRIM                     = "curve.trim"; // Trim Curve

        // === Category: datum ===
        inline constexpr std::string_view DATUM_AXIS                     = "datum.axis"; // Datum Axis
        inline constexpr std::string_view DATUM_CS                       = "datum.cs"; // Coordinate System
        inline constexpr std::string_view DATUM_PLANE                    = "datum.plane"; // Datum Plane
        inline constexpr std::string_view DATUM_POINT                    = "datum.point"; // Point

        // === Category: display ===
        inline constexpr std::string_view DISPLAY_HIDDENLINE             = "display.hiddenLine"; // Hidden Line
        inline constexpr std::string_view DISPLAY_HIDE                   = "display.hide"; // Hide
        inline constexpr std::string_view DISPLAY_ISOLATE                = "display.isolate"; // Isolate
        inline constexpr std::string_view DISPLAY_SHADED                 = "display.shaded"; // Shaded
        inline constexpr std::string_view DISPLAY_SHADEDWITHEDGES        = "display.shadedWithEdges"; // Shaded with Edges
        inline constexpr std::string_view DISPLAY_SHOW                   = "display.show"; // Show
        inline constexpr std::string_view DISPLAY_WIREFRAME              = "display.wireframe"; // Wireframe

        // === Category: edit ===
        inline constexpr std::string_view EDIT_COPY                      = "edit.copy"; // Copy
        inline constexpr std::string_view EDIT_CUT                       = "edit.cut"; // Cut
        inline constexpr std::string_view EDIT_DELETE                    = "edit.delete"; // Delete
        inline constexpr std::string_view EDIT_PASTE                     = "edit.paste"; // Paste
        inline constexpr std::string_view EDIT_REDO                      = "edit.redo"; // Redo
        inline constexpr std::string_view EDIT_SELECTALL                 = "edit.selectAll"; // Select All
        inline constexpr std::string_view EDIT_UNDO                      = "edit.undo"; // Undo

        // === Category: feature ===
        inline constexpr std::string_view MODEL_FEATURE_DELETE           = "model.feature.delete"; // Delete Feature
        inline constexpr std::string_view MODEL_FEATURE_SUPPRESS         = "model.feature.suppress"; // Suppress Feature
        inline constexpr std::string_view MODEL_FEATURE_UNSUPPRESS       = "model.feature.unsuppress"; // Unsuppress Feature

        // === Category: file ===
        inline constexpr std::string_view FILE_CLOSE                     = "file.close"; // Close
        inline constexpr std::string_view FILE_EXIT                      = "file.exit"; // Exit
        inline constexpr std::string_view FILE_NEW                       = "file.new"; // New
        inline constexpr std::string_view FILE_OPEN                      = "file.open"; // Open
        inline constexpr std::string_view FILE_SAVE                      = "file.save"; // Save
        inline constexpr std::string_view FILE_SAVEAS                    = "file.saveAs"; // Save As

        // === Category: gc ===
        inline constexpr std::string_view GC_CHECKUPDATE                 = "gc.checkUpdate"; // Check for Updates
        inline constexpr std::string_view GC_SETTINGS                    = "gc.settings"; // GC Settings
        inline constexpr std::string_view GC_STDPARTLIBRARY              = "gc.stdPartLibrary"; // Standard Parts Library

        // === Category: help ===
        inline constexpr std::string_view HELP_ABOUT                     = "help.about"; // About
        inline constexpr std::string_view HELP_CONTENTS                  = "help.contents"; // Help Contents

        // === Category: measure ===
        inline constexpr std::string_view MEASURE_ANGLE                  = "measure.angle"; // Angle
        inline constexpr std::string_view MEASURE_DIALOG                 = "measure.dialog"; // Measure Dialog
        inline constexpr std::string_view MEASURE_DISTANCE               = "measure.distance"; // Distance
        inline constexpr std::string_view MEASURE_DRAFT                  = "measure.draft"; // Draft Analysis
        inline constexpr std::string_view MEASURE_MASSPROPS              = "measure.massProps"; // Mass Properties
        inline constexpr std::string_view MEASURE_RADIUS                 = "measure.radius"; // Radius
        inline constexpr std::string_view MEASURE_SECTION                = "measure.section"; // Section Measurement

        // === Category: modeling ===
        inline constexpr std::string_view MODEL_CHAMFER                  = "model.chamfer"; // Chamfer
        inline constexpr std::string_view MODEL_DRAFT                    = "model.draft"; // Draft
        inline constexpr std::string_view MODEL_EXTRUDE                  = "model.extrude"; // Extrude
        inline constexpr std::string_view MODEL_FILLET                   = "model.fillet"; // Fillet
        inline constexpr std::string_view MODEL_HOLE                     = "model.hole"; // Hole
        inline constexpr std::string_view MODEL_REVOLVE                  = "model.revolve"; // Revolve
        inline constexpr std::string_view MODEL_SHELL                    = "model.shell"; // Shell
        inline constexpr std::string_view MODEL_SLOT                     = "model.slot"; // Slot

        // === Category: selection ===
        inline constexpr std::string_view SELECT_FILTER                  = "select.filter"; // Selection Filter
        inline constexpr std::string_view SELECT_LASSO                   = "select.lasso"; // Lasso Select
        inline constexpr std::string_view SELECT_RECTANGLE               = "select.rectangle"; // Rectangle Select
        inline constexpr std::string_view SELECT_SINGLE                  = "select.single"; // Single Select

        // === Category: sheet ===
        inline constexpr std::string_view SHEET_BASEFLANGE               = "sheet.baseFlange"; // Base Flange
        inline constexpr std::string_view SHEET_BEND                     = "sheet.bend"; // Bend
        inline constexpr std::string_view SHEET_BREAKCORNER              = "sheet.breakCorner"; // Break Corner
        inline constexpr std::string_view SHEET_CONTOURFLANGE            = "sheet.contourFlange"; // Contour Flange
        inline constexpr std::string_view SHEET_CORNERRELIEF             = "sheet.cornerRelief"; // Corner Relief
        inline constexpr std::string_view SHEET_CUTOUT                   = "sheet.cutout"; // Cutout
        inline constexpr std::string_view SHEET_EDGEFLANGE               = "sheet.edgeFlange"; // Edge Flange
        inline constexpr std::string_view SHEET_EXPORTFLAT               = "sheet.exportFlat"; // Export Flat
        inline constexpr std::string_view SHEET_FLATTEN                  = "sheet.flatten"; // Flat Pattern
        inline constexpr std::string_view SHEET_HOLE                     = "sheet.hole"; // Hole
        inline constexpr std::string_view SHEET_JOG                      = "sheet.jog"; // Jog
        inline constexpr std::string_view SHEET_LOFTEDFLANGE             = "sheet.loftedFlange"; // Lofted Flange
        inline constexpr std::string_view SHEET_REBEND                   = "sheet.rebend"; // Rebend
        inline constexpr std::string_view SHEET_TAB                      = "sheet.tab"; // Tab
        inline constexpr std::string_view SHEET_UNBEND                   = "sheet.unbend"; // Unbend

        // === Category: sketch ===
        inline constexpr std::string_view SKETCH_EDIT                    = "sketch.edit"; // Edit Sketch
        inline constexpr std::string_view SKETCH_MIRROR                  = "sketch.mirror"; // Mirror Sketch
        inline constexpr std::string_view SKETCH_NEW                     = "sketch.new"; // Sketch
        inline constexpr std::string_view SKETCH_REUSE                   = "sketch.reuse"; // Reuse Sketch

        // === Category: sketch.constraint ===
        inline constexpr std::string_view SKETCH_CONSTRAINT_COINCIDENT   = "sketch.constraint.coincident"; // Coincident
        inline constexpr std::string_view SKETCH_CONSTRAINT_EQUAL        = "sketch.constraint.equal"; // Equal
        inline constexpr std::string_view SKETCH_CONSTRAINT_FIX          = "sketch.constraint.fix"; // Fix
        inline constexpr std::string_view SKETCH_CONSTRAINT_HORIZONTAL   = "sketch.constraint.horizontal"; // Horizontal
        inline constexpr std::string_view SKETCH_CONSTRAINT_PARALLEL     = "sketch.constraint.parallel"; // Parallel
        inline constexpr std::string_view SKETCH_CONSTRAINT_PERPENDICULAR = "sketch.constraint.perpendicular"; // Perpendicular
        inline constexpr std::string_view SKETCH_CONSTRAINT_SYMMETRIC    = "sketch.constraint.symmetric"; // Symmetric
        inline constexpr std::string_view SKETCH_CONSTRAINT_TANGENT      = "sketch.constraint.tangent"; // Tangent
        inline constexpr std::string_view SKETCH_CONSTRAINT_VERTICAL     = "sketch.constraint.vertical"; // Vertical

        // === Category: sketch.dim ===
        inline constexpr std::string_view SKETCH_DIM_ANGLE               = "sketch.dim.angle"; // Angular Dimension
        inline constexpr std::string_view SKETCH_DIM_DIAMETER            = "sketch.dim.diameter"; // Diameter Dimension
        inline constexpr std::string_view SKETCH_DIM_GENERAL             = "sketch.dim.general"; // Smart Dimension
        inline constexpr std::string_view SKETCH_DIM_HORIZONTAL          = "sketch.dim.horizontal"; // Horizontal Dimension
        inline constexpr std::string_view SKETCH_DIM_RADIUS              = "sketch.dim.radius"; // Radius Dimension
        inline constexpr std::string_view SKETCH_DIM_VERTICAL            = "sketch.dim.vertical"; // Vertical Dimension

        // === Category: sketch.modify ===
        inline constexpr std::string_view SKETCH_MODIFY_EXTEND           = "sketch.modify.extend"; // Extend
        inline constexpr std::string_view SKETCH_MODIFY_FILLET           = "sketch.modify.fillet"; // Fillet
        inline constexpr std::string_view SKETCH_MODIFY_MIRROR           = "sketch.modify.mirror"; // Mirror
        inline constexpr std::string_view SKETCH_MODIFY_OFFSET           = "sketch.modify.offset"; // Offset
        inline constexpr std::string_view SKETCH_MODIFY_PATTERN          = "sketch.modify.pattern"; // Pattern
        inline constexpr std::string_view SKETCH_MODIFY_TRIM             = "sketch.modify.trim"; // Trim

        // === Category: synchronous ===
        inline constexpr std::string_view SMOVE_FACE                     = "smove.face"; // Move Face
        inline constexpr std::string_view SYNCHRONOUS_DELETEFACE         = "synchronous.deleteFace"; // Delete Face
        inline constexpr std::string_view SYNCHRONOUS_OFFSETREGION       = "synchronous.offsetRegion"; // Offset Region
        inline constexpr std::string_view SYNCHRONOUS_PULL               = "synchronous.pull"; // Pull Face

        // === Category: tools ===
        inline constexpr std::string_view TOOLS_COMMANDLINE              = "tools.commandLine"; // Command Line
        inline constexpr std::string_view TOOLS_EXPRESSIONS              = "tools.expressions"; // Expressions
        inline constexpr std::string_view TOOLS_JOURNAL_PAUSE            = "tools.journal.pause"; // Pause Journal
        inline constexpr std::string_view TOOLS_JOURNAL_PLAY             = "tools.journal.play"; // Play Journal
        inline constexpr std::string_view TOOLS_JOURNAL_RECORD           = "tools.journal.record"; // Record Journal
        inline constexpr std::string_view TOOLS_PYTHONCONSOLE            = "tools.pythonConsole"; // Python Console

        // === Category: ui ===
        inline constexpr std::string_view UI_RESTORELAYOUT               = "ui.restoreLayout"; // Restore Layout
        inline constexpr std::string_view UI_SAVELAYOUT                  = "ui.saveLayout"; // Save Layout
        inline constexpr std::string_view UI_TOGGLEMODE                  = "ui.toggleMode"; // Toggle Ribbon / Classic

        // === Category: view ===
        inline constexpr std::string_view VIEW_CLIPPINGPLANE             = "view.clippingPlane"; // Clipping Plane
        inline constexpr std::string_view VIEW_DYNAMICSECTION            = "view.dynamicSection"; // Dynamic Section
        inline constexpr std::string_view VIEW_FRONT                     = "view.front"; // Front
        inline constexpr std::string_view VIEW_RIGHT                     = "view.right"; // Right
        inline constexpr std::string_view VIEW_TOP                       = "view.top"; // Top
        inline constexpr std::string_view VIEW_TRIMETRIC                 = "view.trimetric"; // Trimetric

        // === Category: window ===
        inline constexpr std::string_view WINDOW_ARRANGE                 = "window.arrange"; // Arrange Windows
        inline constexpr std::string_view WINDOW_NEW                     = "window.new"; // New Window
        inline constexpr std::string_view WINDOW_TILEHORIZONTAL          = "window.tileHorizontal"; // Tile Horizontally

    } // namespace Cmd
} // namespace sdr
