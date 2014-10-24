#include "stdafx.h"
#include "text_ui_state_factory.h"
#include "text_ui_state.h"
#include "menu_state.h"
#include "create_mind_map_state.h"
#include "insert_menu_state.h"
#include "edit_menu_state.h"
#include "edit_description_state.h"
#include "change_parent_state.h"
#include "delete_node_state.h"
#include "display_mind_map_state.h"
#include "save_state.h"
#include "load_state.h"
#include "undo_state.h"
#include "redo_state.h"
#include "exit_state.h"


TextUIStateFactory::TextUIStateFactory()
{
}


TextUIStateFactory::~TextUIStateFactory()
{
}


TextUIState* TextUIStateFactory::createTextUIState(TextUIStateEnum textUIState, MindMapModel* mindMapModel, Component* component)
{
    switch (textUIState) {
        case MenuStateInstruction:
            return new MenuState(mindMapModel);
            break;
        case CreateMindMapStateInstruction:
            return new CreateMindMapState(mindMapModel);
            break;
        case InsertMenuStateInstruction:
            return new InsertMenuState(mindMapModel);
            break;
        case EditMenuStateInstruction:
            return new EditMenuState(mindMapModel);
            break;
        case EditDescriptionStateInstruction:
            return new EditDescriptionState(mindMapModel, component);
            break;
        case ChangeParentStateInstruction:
            return new ChangeParentState(mindMapModel, component);
            break;
        case DeleteNodeStateInstruction:
            return new DeleteNodeState(mindMapModel, component);
            break;
        case DisplayMindMapStateInstruction:
            return new DisplayMindMapState(mindMapModel);
            break;
        case SaveStateInstruction:
            return new SaveState(mindMapModel);
            break;
        case LoadStateInstruction:
            return new LoadState(mindMapModel);
            break;
        case RedoStateInstruction:
            return new RedoState(mindMapModel);
            break;
        case UndoStateInstruction:
            return new UndoState(mindMapModel);
            break;
        case ExitStateInstruction:
            return new ExitState(mindMapModel);
            break;
        default:
            return NULL;
            break;
    }
}