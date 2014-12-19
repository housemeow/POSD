#include "stdafx.h"
#include "text_ui_state_factory.h"
#include "text_ui_state.h"
#include "menu_state.h"
#include "create_mind_map_state.h"
#include "insert_menu_state.h"
#include "insert_parent_node_state.h"
#include "insert_child_node_state.h"
#include "insert_sibling_node_state.h"
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
        case CreateMindMapStateInstruction:
            return new CreateMindMapState(mindMapModel);
        case InsertMenuStateInstruction:
            return new InsertMenuState(mindMapModel);
        case InsertParentNodeStateInstruction:
            return new InsertParentNodeState(mindMapModel, component);
        case InsertChildNodeStateInstruction:
            return new InsertChildNodeState(mindMapModel, component);
        case InsertSiblingNodeStateInstruction:
            return new InsertSiblingNodeState(mindMapModel, component);
        case EditMenuStateInstruction:
            return new EditMenuState(mindMapModel);
        case EditDescriptionStateInstruction:
            return new EditDescriptionState(mindMapModel, component);
        case ChangeParentStateInstruction:
            return new ChangeParentState(mindMapModel, component);
        case DeleteNodeStateInstruction:
            return new DeleteNodeState(mindMapModel, component);
        case DisplayMindMapStateInstruction:
            return new DisplayMindMapState(mindMapModel);
        case SaveStateInstruction:
            return new SaveState(mindMapModel);
        case LoadStateInstruction:
            return new LoadState(mindMapModel);
        case RedoStateInstruction:
            return new RedoState(mindMapModel);
        case UndoStateInstruction:
            return new UndoState(mindMapModel);
        case ExitStateInstruction:
            return new ExitState(mindMapModel);
        default:
            return NULL;
    }
}