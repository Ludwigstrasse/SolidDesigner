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

        // === Category: curve ===
        inline constexpr std::string_view CURVE_ARC                      = "curve.arc"; // Arc
        inline constexpr std::string_view CURVE_ARC_3POINTTANGENTEND     = "curve.arc.3PointTangentEnd"; // 3-Point / Tangent End
        inline constexpr std::string_view CURVE_ARC_3TANGENT             = "curve.arc.3Tangent"; // 3 Tangent
        inline constexpr std::string_view CURVE_ARC_CENTERANDENDS        = "curve.arc.centerAndEnds"; // Center and Ends
        inline constexpr std::string_view CURVE_ARC_CONCENTRIC           = "curve.arc.concentric"; // Concentric
        inline constexpr std::string_view CURVE_ARC_CONIC                = "curve.arc.conic"; // Conic
        inline constexpr std::string_view CURVE_CENTERLINE               = "curve.centerline"; // Centerline
        inline constexpr std::string_view CURVE_CIRCLE                   = "curve.circle"; // Circle
        inline constexpr std::string_view CURVE_CIRCLE_3POINT            = "curve.circle.3Point"; // 3 Point
        inline constexpr std::string_view CURVE_CIRCLE_3TANGENT          = "curve.circle.3Tangent"; // 3 Tangent
        inline constexpr std::string_view CURVE_CIRCLE_CENTERANDPOINT    = "curve.circle.centerAndPoint"; // Center and Point
        inline constexpr std::string_view CURVE_CIRCLE_CONCENTRIC        = "curve.circle.concentric"; // Concentric
        inline constexpr std::string_view CURVE_ELLIPSE                  = "curve.ellipse"; // Ellipse
        inline constexpr std::string_view CURVE_ELLIPSE_AXISANDENDS      = "curve.ellipse.axisAndEnds"; // Axis and Ends Ellipse
        inline constexpr std::string_view CURVE_ELLIPSE_CENTERANDAXIS    = "curve.ellipse.centerAndAxis"; // Center and Axis Ellipse
        inline constexpr std::string_view CURVE_EXTEND                   = "curve.extend"; // Extend Curve
        inline constexpr std::string_view CURVE_FILLET                   = "curve.fillet"; // Curve Fillet
        inline constexpr std::string_view CURVE_FITSPLINE                = "curve.fitSpline"; // Fit Spline
        inline constexpr std::string_view CURVE_JOIN                     = "curve.join"; // Join Curves
        inline constexpr std::string_view CURVE_LINE                     = "curve.line"; // Line
        inline constexpr std::string_view CURVE_OFFSET                   = "curve.offset"; // Offset Curve
        inline constexpr std::string_view CURVE_POINT                    = "curve.point"; // Point
        inline constexpr std::string_view CURVE_RECTANGLE                = "curve.rectangle"; // Rectangle
        inline constexpr std::string_view CURVE_RECTANGLE_CENTER         = "curve.rectangle.center"; // Center Rectangle
        inline constexpr std::string_view CURVE_RECTANGLE_CORNER         = "curve.rectangle.corner"; // Corner Rectangle
        inline constexpr std::string_view CURVE_RECTANGLE_PARALLELOGRAM  = "curve.rectangle.parallelogram"; // Parallelogram
        inline constexpr std::string_view CURVE_RECTANGLE_SLANTED        = "curve.rectangle.slanted"; // Slanted Rectangle
        inline constexpr std::string_view CURVE_SPLINETHROUGH            = "curve.splineThrough"; // Spline Through Points
        inline constexpr std::string_view CURVE_STUDIOSPLINE             = "curve.studioSpline"; // Studio Spline
        inline constexpr std::string_view CURVE_TRIM                     = "curve.trim"; // Trim Curve

        // === Category: data ===
        inline constexpr std::string_view DATA_ERASENOTDISPLAYED         = "data.eraseNotDisplayed"; // Erase Not Displayed
        inline constexpr std::string_view DATA_OPENLASTSESSION           = "data.openLastSession"; // Open Last Session
        inline constexpr std::string_view DATA_SELECTWORKINGDIRECTORY    = "data.selectWorkingDirectory"; // Select Working Directory

        // === Category: datum ===
        inline constexpr std::string_view DATUM_AXIS                     = "datum.axis"; // Axis
        inline constexpr std::string_view DATUM_CS                       = "datum.cs"; // Coordinate System
        inline constexpr std::string_view DATUM_CURVE                    = "datum.curve"; // Curve
        inline constexpr std::string_view DATUM_DEFAULTCOORDINATESYSTEM  = "datum.defaultCoordinateSystem"; // Default Coordinate System
        inline constexpr std::string_view DATUM_GRAPH                    = "datum.graph"; // Graph
        inline constexpr std::string_view DATUM_OFFSETPLANES             = "datum.offsetPlanes"; // Offset Planes
        inline constexpr std::string_view DATUM_PLANE                    = "datum.plane"; // Plane
        inline constexpr std::string_view DATUM_POINT                    = "datum.point"; // Point
        inline constexpr std::string_view DATUM_REFERENCE                = "datum.reference"; // Reference
        inline constexpr std::string_view DATUM_RIBBON                   = "datum.ribbon"; // Ribbon

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

        // === Category: editing ===
        inline constexpr std::string_view MODEL_EXTEND                   = "model.extend"; // Extend
        inline constexpr std::string_view MODEL_INTERSECT                = "model.intersect"; // Intersect
        inline constexpr std::string_view MODEL_MERGE                    = "model.merge"; // Merge
        inline constexpr std::string_view MODEL_MIRROR                   = "model.mirror"; // Mirror
        inline constexpr std::string_view MODEL_OFFSET                   = "model.offset"; // Offset
        inline constexpr std::string_view MODEL_PROJECT                  = "model.project"; // Project
        inline constexpr std::string_view MODEL_PROJECT_COLLAPSE         = "model.project.collapse"; // Collapse
        inline constexpr std::string_view MODEL_PROJECT_FLIPNORMAL       = "model.project.flipNormal"; // Flip Normal
        inline constexpr std::string_view MODEL_PROJECT_REMOVE           = "model.project.remove"; // Remove
        inline constexpr std::string_view MODEL_PROJECT_SPLITSURFACE     = "model.project.splitSurface"; // Split Surface
        inline constexpr std::string_view MODEL_PROJECT_WRAP             = "model.project.wrap"; // Wrap
        inline constexpr std::string_view MODEL_SOLIDIFY                 = "model.solidify"; // Solidify
        inline constexpr std::string_view MODEL_THICKEN                  = "model.thicken"; // Thicken
        inline constexpr std::string_view MODEL_TRIM                     = "model.trim"; // Trim

        // === Category: engineering ===
        inline constexpr std::string_view MODEL_AREA_DESIGNATED          = "model.area.designated"; // Designated Area
        inline constexpr std::string_view MODEL_AREA_ECAD                = "model.area.ecad"; // ECAD Area
        inline constexpr std::string_view MODEL_BEND_SPIRAL              = "model.bend.spiral"; // Spiral Bend
        inline constexpr std::string_view MODEL_BEND_TOROIDAL            = "model.bend.toroidal"; // Toroidal Bend
        inline constexpr std::string_view MODEL_CHAMFER                  = "model.chamfer"; // Chamfer
        inline constexpr std::string_view MODEL_CHAMFER_CORNER           = "model.chamfer.corner"; // Corner Chamfer
        inline constexpr std::string_view MODEL_CHAMFER_EDGE             = "model.chamfer.edge"; // Edge Chamfer
        inline constexpr std::string_view MODEL_COSMETIC_GROOVE          = "model.cosmetic.groove"; // Cosmetic Groove
        inline constexpr std::string_view MODEL_COSMETIC_SKETCH          = "model.cosmetic.sketch"; // Cosmetic Sketch
        inline constexpr std::string_view MODEL_COSMETIC_THREAD          = "model.cosmetic.thread"; // Cosmetic Thread
        inline constexpr std::string_view MODEL_DRAFT                    = "model.draft"; // Draft
        inline constexpr std::string_view MODEL_DRAFT_VARIABLEPULLDIRECTION = "model.draft.variablePullDirection"; // Variable Pull Direction Draft
        inline constexpr std::string_view MODEL_HOLE                     = "model.hole"; // Hole
        inline constexpr std::string_view MODEL_LATTICE                  = "model.lattice"; // Lattice
        inline constexpr std::string_view MODEL_RIB                      = "model.rib"; // Rib
        inline constexpr std::string_view MODEL_RIB_PROFILE              = "model.rib.profile"; // Profile Rib
        inline constexpr std::string_view MODEL_RIB_TRAJECTORY           = "model.rib.trajectory"; // Trajectory Rib
        inline constexpr std::string_view MODEL_ROUND                    = "model.round"; // Round
        inline constexpr std::string_view MODEL_ROUND_AUTO               = "model.round.auto"; // Auto Round
        inline constexpr std::string_view MODEL_SHELL                    = "model.shell"; // Shell

        // === Category: feature ===
        inline constexpr std::string_view MODEL_FEATURE_DELETE           = "model.feature.delete"; // Delete Feature
        inline constexpr std::string_view MODEL_FEATURE_SUPPRESS         = "model.feature.suppress"; // Suppress
        inline constexpr std::string_view MODEL_FEATURE_UNSUPPRESS       = "model.feature.unsuppress"; // Resume

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
        inline constexpr std::string_view CMD_HELP_CONTENTS              = "help.contents"; // Help Contents

        // === Category: measure ===
        inline constexpr std::string_view MEASURE_ANGLE                  = "measure.angle"; // Angle
        inline constexpr std::string_view MEASURE_DIALOG                 = "measure.dialog"; // Measure Dialog
        inline constexpr std::string_view MEASURE_DISTANCE               = "measure.distance"; // Distance
        inline constexpr std::string_view MEASURE_DRAFT                  = "measure.draft"; // Draft Analysis
        inline constexpr std::string_view MEASURE_MASSPROPS              = "measure.massProps"; // Mass Properties
        inline constexpr std::string_view MEASURE_RADIUS                 = "measure.radius"; // Radius
        inline constexpr std::string_view MEASURE_SECTION                = "measure.section"; // Section Measurement

        // === Category: model.getData ===
        inline constexpr std::string_view MODEL_GETDATA_COPYFROM         = "model.getData.copyFrom"; // Copy From
        inline constexpr std::string_view MODEL_GETDATA_COPYGEOMETRY     = "model.getData.copyGeometry"; // Copy Geometry
        inline constexpr std::string_view MODEL_GETDATA_IMPORT           = "model.getData.import"; // Import
        inline constexpr std::string_view MODEL_GETDATA_INDEPENDENTGEOMETRY = "model.getData.independentGeometry"; // Independent Geometry
        inline constexpr std::string_view MODEL_GETDATA_LAYOUTFEATURE    = "model.getData.layoutFeature"; // Layout Feature
        inline constexpr std::string_view MODEL_GETDATA_MERGEINHERITANCE = "model.getData.mergeInheritance"; // Merge/Inheritance
        inline constexpr std::string_view MODEL_GETDATA_SHRINKWRAP       = "model.getData.shrinkwrap"; // Shrinkwrap
        inline constexpr std::string_view MODEL_GETDATA_USERDEFINEDFEATURE = "model.getData.userDefinedFeature"; // User-Defined Feature

        // === Category: model.ops ===
        inline constexpr std::string_view MODEL_DELETE                   = "model.delete"; // Delete
        inline constexpr std::string_view MODEL_REGENERATE               = "model.regenerate"; // Regenerate

        // === Category: modelIntent ===
        inline constexpr std::string_view MODELINTENT_COMPONENTINTERFACE = "modelIntent.componentInterface"; // Component Interface
        inline constexpr std::string_view MODELINTENT_FAMILYTABLE        = "modelIntent.familyTable"; // Family Table
        inline constexpr std::string_view MODELINTENT_PARAMETERS         = "modelIntent.parameters"; // Parameters
        inline constexpr std::string_view MODELINTENT_PUBLISHGEOMETRY    = "modelIntent.publishGeometry"; // Publish Geometry
        inline constexpr std::string_view MODELINTENT_SWITCHDIMENSIONS   = "modelIntent.switchDimensions"; // Switch Dimensions

        // === Category: pattern ===
        inline constexpr std::string_view MODEL_PATTERN                  = "model.pattern"; // Pattern
        inline constexpr std::string_view MODEL_PATTERN_GEOMETRY         = "model.pattern.geometry"; // Geometry Pattern
        inline constexpr std::string_view MODEL_PATTERN_TABLE            = "model.pattern.table"; // Pattern Table

        // === Category: selection ===
        inline constexpr std::string_view SELECT_FILTER                  = "select.filter"; // Selection Filter
        inline constexpr std::string_view SELECT_LASSO                   = "select.lasso"; // Lasso Select
        inline constexpr std::string_view SELECT_RECTANGLE               = "select.rectangle"; // Rectangle Select
        inline constexpr std::string_view SELECT_SINGLE                  = "select.single"; // Single Select
        inline constexpr std::string_view SKETCH_SELECT                  = "sketch.select"; // Select

        // === Category: settings ===
        inline constexpr std::string_view SETTINGS_MODELDISPLAY          = "settings.modelDisplay"; // Model Display
        inline constexpr std::string_view SETTINGS_SYSTEMAPPEARANCE      = "settings.systemAppearance"; // System Appearance

        // === Category: shapes ===
        inline constexpr std::string_view MODEL_BLEND                    = "model.blend"; // Blend
        inline constexpr std::string_view MODEL_BLEND_ROTATIONAL         = "model.blend.rotational"; // Rotational Blend
        inline constexpr std::string_view MODEL_EXTRUDE                  = "model.extrude"; // Extrude
        inline constexpr std::string_view MODEL_REVOLVE                  = "model.revolve"; // Revolve
        inline constexpr std::string_view MODEL_SWEEP                    = "model.sweep"; // Sweep
        inline constexpr std::string_view MODEL_SWEEP_HELICAL            = "model.sweep.helical"; // Helical Sweep
        inline constexpr std::string_view MODEL_SWEEP_VOLUMEHELICAL      = "model.sweep.volumeHelical"; // Volume Helical Sweep
        inline constexpr std::string_view MODEL_SWEEPBLEND               = "model.sweepBlend"; // Sweep Blend

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
        inline constexpr std::string_view SKETCH_DISPLAY_CONSTRAINTS     = "sketch.display.constraints"; // Constraints Display
        inline constexpr std::string_view SKETCH_DISPLAY_DIMENSIONS      = "sketch.display.dimensions"; // Dimensions Display
        inline constexpr std::string_view SKETCH_DISPLAY_GRID            = "sketch.display.grid"; // Grid Display
        inline constexpr std::string_view SKETCH_DISPLAY_VERTICES        = "sketch.display.vertices"; // Vertices Display
        inline constexpr std::string_view SKETCH_EDIT                    = "sketch.edit"; // Edit Sketch
        inline constexpr std::string_view SKETCH_FILESYSTEM              = "sketch.fileSystem"; // File System
        inline constexpr std::string_view SKETCH_GRIDSETTINGS            = "sketch.gridSettings"; // Grid Settings
        inline constexpr std::string_view SKETCH_INSPECT_ENTITY          = "sketch.inspect.entity"; // Entity
        inline constexpr std::string_view SKETCH_INSPECT_FEATUREREQUIREMENTS = "sketch.inspect.featureRequirements"; // Feature Requirements
        inline constexpr std::string_view SKETCH_INSPECT_INTERSECTIONPOINT = "sketch.inspect.intersectionPoint"; // Intersection Point
        inline constexpr std::string_view SKETCH_INSPECT_TANGENCYPOINT   = "sketch.inspect.tangencyPoint"; // Tangency Point
        inline constexpr std::string_view SKETCH_LINESTYLE_CLEAR         = "sketch.lineStyle.clear"; // Clear Line Style
        inline constexpr std::string_view SKETCH_LINESTYLE_SET           = "sketch.lineStyle.set"; // Set Line Style
        inline constexpr std::string_view SKETCH_MIRROR                  = "sketch.mirror"; // Mirror Sketch
        inline constexpr std::string_view SKETCH_NEW                     = "sketch.new"; // Sketch
        inline constexpr std::string_view SKETCH_PROPERTIES              = "sketch.properties"; // Properties
        inline constexpr std::string_view SKETCH_REFERENCES              = "sketch.references"; // References
        inline constexpr std::string_view SKETCH_REUSE                   = "sketch.reuse"; // Reuse Sketch
        inline constexpr std::string_view SKETCH_SECTION_FLIPSECTIONORIENTATION = "sketch.section.flipSectionOrientation"; // Flip section orientation
        inline constexpr std::string_view SKETCH_SECTION_FLIPSKETCHINGPLANE = "sketch.section.flipSketchingPlane"; // Flip sketching plane
        inline constexpr std::string_view SKETCH_SECTION_RESTORESECTIONORIENTATION = "sketch.section.restoreSectionOrientation"; // Restore section orientation
        inline constexpr std::string_view SKETCH_SECTION_SETHORIZONTALREFERENCE = "sketch.section.setHorizontalReference"; // Set horizontal reference
        inline constexpr std::string_view SKETCH_SECTION_SETVERTICALREFERENCE = "sketch.section.setVerticalReference"; // Set vertical reference
        inline constexpr std::string_view SKETCH_SETUP                   = "sketch.setup"; // Sketch Setup
        inline constexpr std::string_view SKETCH_TEXT                    = "sketch.text"; // Text
        inline constexpr std::string_view SKETCH_UNDERCONSTRAINEDMODE    = "sketch.underConstrainedMode"; // Under-Constrained Mode
        inline constexpr std::string_view SKETCH_VIEW                    = "sketch.view"; // Sketch View

        // === Category: sketch.constraint ===
        inline constexpr std::string_view SKETCH_CONSTRAINT_COINCIDENT   = "sketch.constraint.coincident"; // Coincident
        inline constexpr std::string_view SKETCH_CONSTRAINT_EQUAL        = "sketch.constraint.equal"; // Equal
        inline constexpr std::string_view SKETCH_CONSTRAINT_FIX          = "sketch.constraint.fix"; // Fix
        inline constexpr std::string_view SKETCH_CONSTRAINT_HORIZONTAL   = "sketch.constraint.horizontal"; // Horizontal
        inline constexpr std::string_view SKETCH_CONSTRAINT_MIDPOINT     = "sketch.constraint.midPoint"; // Mid-point
        inline constexpr std::string_view SKETCH_CONSTRAINT_PARALLEL     = "sketch.constraint.parallel"; // Parallel
        inline constexpr std::string_view SKETCH_CONSTRAINT_PERPENDICULAR = "sketch.constraint.perpendicular"; // Perpendicular
        inline constexpr std::string_view SKETCH_CONSTRAINT_SYMMETRIC    = "sketch.constraint.symmetric"; // Symmetric
        inline constexpr std::string_view SKETCH_CONSTRAINT_TANGENT      = "sketch.constraint.tangent"; // Tangent
        inline constexpr std::string_view SKETCH_CONSTRAINT_VERTICAL     = "sketch.constraint.vertical"; // Vertical

        // === Category: sketch.dim ===
        inline constexpr std::string_view SKETCH_DIM_ANGLE               = "sketch.dim.angle"; // Angular Dimension
        inline constexpr std::string_view SKETCH_DIM_BASELINE            = "sketch.dim.baseline"; // Baseline
        inline constexpr std::string_view SKETCH_DIM_DIAMETER            = "sketch.dim.diameter"; // Diameter Dimension
        inline constexpr std::string_view SKETCH_DIM_DIMENSION           = "sketch.dim.dimension"; // Dimension
        inline constexpr std::string_view SKETCH_DIM_GENERAL             = "sketch.dim.general"; // Smart Dimension
        inline constexpr std::string_view SKETCH_DIM_HORIZONTAL          = "sketch.dim.horizontal"; // Horizontal Dimension
        inline constexpr std::string_view SKETCH_DIM_PERIMETER           = "sketch.dim.perimeter"; // Perimeter
        inline constexpr std::string_view SKETCH_DIM_RADIUS              = "sketch.dim.radius"; // Radius Dimension
        inline constexpr std::string_view SKETCH_DIM_REFERENCE           = "sketch.dim.reference"; // Reference
        inline constexpr std::string_view SKETCH_DIM_VERTICAL            = "sketch.dim.vertical"; // Vertical Dimension

        // === Category: sketch.modify ===
        inline constexpr std::string_view SKETCH_FILLET_CIRCULAR         = "sketch.fillet.circular"; // Circular
        inline constexpr std::string_view SKETCH_FILLET_CIRCULARTRIM     = "sketch.fillet.circularTrim"; // Circular Trim
        inline constexpr std::string_view SKETCH_FILLET_ELLIPTICAL       = "sketch.fillet.elliptical"; // Elliptical
        inline constexpr std::string_view SKETCH_FILLET_ELLIPTICALTRIM   = "sketch.fillet.ellipticalTrim"; // Elliptical Trim
        inline constexpr std::string_view SKETCH_MODIFY_CHAMFER          = "sketch.modify.chamfer"; // Chamfer
        inline constexpr std::string_view SKETCH_MODIFY_CHAMFERTRIM      = "sketch.modify.chamferTrim"; // Chamfer Trim
        inline constexpr std::string_view SKETCH_MODIFY_CORNER           = "sketch.modify.corner"; // Corner
        inline constexpr std::string_view SKETCH_MODIFY_DELETESEGMENT    = "sketch.modify.deleteSegment"; // Delete Segment
        inline constexpr std::string_view SKETCH_MODIFY_DIVIDE           = "sketch.modify.divide"; // Divide
        inline constexpr std::string_view SKETCH_MODIFY_EXTEND           = "sketch.modify.extend"; // Extend
        inline constexpr std::string_view SKETCH_MODIFY_FILLET           = "sketch.modify.fillet"; // Fillet
        inline constexpr std::string_view SKETCH_MODIFY_MIRROR           = "sketch.modify.mirror"; // Mirror
        inline constexpr std::string_view SKETCH_MODIFY_MODIFY           = "sketch.modify.modify"; // Modify
        inline constexpr std::string_view SKETCH_MODIFY_OFFSET           = "sketch.modify.offset"; // Offset
        inline constexpr std::string_view SKETCH_MODIFY_PATTERN          = "sketch.modify.pattern"; // Pattern
        inline constexpr std::string_view SKETCH_MODIFY_ROTATERESIZE     = "sketch.modify.rotateResize"; // Rotate Resize
        inline constexpr std::string_view SKETCH_MODIFY_TRIM             = "sketch.modify.trim"; // Trim
        inline constexpr std::string_view SKETCH_OPS_CONSTRUCTION        = "sketch.ops.construction"; // Construction
        inline constexpr std::string_view SKETCH_OPS_CONVERTTO           = "sketch.ops.convertTo"; // Convert To
        inline constexpr std::string_view SKETCH_OPS_DELETE              = "sketch.ops.delete"; // Delete
        inline constexpr std::string_view SKETCH_OPS_REPLACE             = "sketch.ops.replace"; // Replace
        inline constexpr std::string_view SKETCH_OPS_TOGGLELOCK          = "sketch.ops.toggleLock"; // Toggle Lock
        inline constexpr std::string_view SKETCH_PROJECT                 = "sketch.project"; // Project
        inline constexpr std::string_view SKETCH_THICKEN                 = "sketch.thicken"; // Thicken

        // === Category: surface ===
        inline constexpr std::string_view SURFACE_BOUNDARYBLEND          = "surface.boundaryBlend"; // Boundary Blend
        inline constexpr std::string_view SURFACE_FILL                   = "surface.fill"; // Fill
        inline constexpr std::string_view SURFACE_FREESTYLE              = "surface.freestyle"; // Freestyle
        inline constexpr std::string_view SURFACE_STYLE                  = "surface.style"; // Style
        inline constexpr std::string_view SURFACE_STYLE_BLENDTANGENT     = "surface.style.blendTangent"; // Blend Tangent to Surfaces
        inline constexpr std::string_view SURFACE_STYLE_FLATTENQUILT     = "surface.style.flattenQuilt"; // Flatten Quilt
        inline constexpr std::string_view SURFACE_STYLE_FLATTENQUILTDEFORMATION = "surface.style.flattenQuiltDeformation"; // Flatten-Quilt Deformation
        inline constexpr std::string_view SURFACE_STYLE_FOREIGNSURFACE   = "surface.style.foreignSurface"; // Foreign Surface
        inline constexpr std::string_view SURFACE_STYLE_RESTYLE          = "surface.style.restyle"; // Restyle
        inline constexpr std::string_view SURFACE_STYLE_VERTEXROUND      = "surface.style.vertexRound"; // Vertex Round

        // === Category: synchronous ===
        inline constexpr std::string_view SMOVE_FACE                     = "smove.face"; // Move Face
        inline constexpr std::string_view SYNCHRONOUS_DELETEFACE         = "synchronous.deleteFace"; // Delete Face
        inline constexpr std::string_view SYNCHRONOUS_OFFSETREGION       = "synchronous.offsetRegion"; // Offset Region
        inline constexpr std::string_view SYNCHRONOUS_PULL               = "synchronous.pull"; // Pull

        // === Category: tools ===
        inline constexpr std::string_view TOOLS_COMMANDLINE              = "tools.commandLine"; // Command Line
        inline constexpr std::string_view TOOLS_EXPRESSIONS              = "tools.expressions"; // Expressions
        inline constexpr std::string_view TOOLS_JOURNAL_PAUSE            = "tools.journal.pause"; // Pause Journal
        inline constexpr std::string_view TOOLS_JOURNAL_PLAY             = "tools.journal.play"; // Play Journal
        inline constexpr std::string_view TOOLS_JOURNAL_RECORD           = "tools.journal.record"; // Record Journal
        inline constexpr std::string_view TOOLS_PYTHONCONSOLE            = "tools.pythonConsole"; // Python Console

        // === Category: ui ===
        inline constexpr std::string_view SKETCH_CANCEL                  = "sketch.cancel"; // Cancel
        inline constexpr std::string_view SKETCH_OK                      = "sketch.ok"; // OK
        inline constexpr std::string_view UI_RESTORELAYOUT               = "ui.restoreLayout"; // Restore Layout
        inline constexpr std::string_view UI_SAVELAYOUT                  = "ui.saveLayout"; // Save Layout
        inline constexpr std::string_view UI_TOGGLEMODE                  = "ui.toggleMode"; // Toggle Ribbon / Classic

        // === Category: ui.titlebar ===
        inline constexpr std::string_view UI_APPMENU                     = "ui.appMenu"; // SolidDesigner
        inline constexpr std::string_view UI_QATMENU                     = "ui.qatMenu"; // Quick Access
        inline constexpr std::string_view UI_WINDOWSMENU                 = "ui.windowsMenu"; // Windows

        // === Category: utilities ===
        inline constexpr std::string_view UTILITIES_AUXAPPLICATION       = "utilities.auxApplication"; // Auxiliary Application
        inline constexpr std::string_view UTILITIES_PLAYTRAILFILE        = "utilities.playTrailFile"; // Play Trail File

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
