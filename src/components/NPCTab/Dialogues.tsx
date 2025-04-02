import { useState, useEffect } from 'react';
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Textarea } from "@/components/ui/textarea";
import { Button } from "@/components/ui/button";
import { Card, CardContent } from "@/components/ui/card";
import { Plus, Minus, Trash2, ArrowRight } from 'lucide-react';
import { NPCItem, NPCDialogue } from '../../types/npcTypes';

interface DialoguesProps {
  npc: NPCItem;
  onUpdateNPC: (updatedNPC: NPCItem, field?: string, oldValue?: any) => void;
  editMode: boolean;
}

const Dialogues = ({ npc, onUpdateNPC, editMode }: DialoguesProps) => {
  const [localNPC, setLocalNPC] = useState<NPCItem>(npc);
  const [selectedDialogueId, setSelectedDialogueId] = useState<string | null>(null);
  const [dialogPreview, setDialogPreview] = useState<string>('');

  // Aktualisieren des lokalen Zustands, wenn sich der NPC ändert
  useEffect(() => {
    setLocalNPC(npc);
    // Wenn ein Dialog ausgewählt ist, aktualisiere auch die Dialogvorschau
    if (selectedDialogueId) {
      const selectedDialogue = npc.dialogues?.find(d => d.id === selectedDialogueId);
      if (selectedDialogue) {
        setDialogPreview(selectedDialogue.text);
      }
    }
  }, [npc, selectedDialogueId]);

  // Dialog hinzufügen
  const handleAddDialogue = () => {
    if (!editMode) return;
    
    const newId = `dialog_${Date.now()}`;
    const newDialogue: NPCDialogue = {
      id: newId,
      text: 'Neuer Dialog',
      responses: []
    };
    
    const updatedDialogues = [...(localNPC.dialogues || []), newDialogue];
    const updatedNPC = { ...localNPC, dialogues: updatedDialogues };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'dialogues', localNPC.dialogues);
    setSelectedDialogueId(newId);
  };

  // Dialog löschen
  const handleDeleteDialogue = (id: string) => {
    if (!editMode || !localNPC.dialogues) return;
    
    const updatedDialogues = localNPC.dialogues.filter(d => d.id !== id);
    const updatedNPC = { ...localNPC, dialogues: updatedDialogues };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'dialogues', localNPC.dialogues);
    
    if (selectedDialogueId === id) {
      setSelectedDialogueId(updatedDialogues.length > 0 ? updatedDialogues[0].id : null);
    }
  };

  // Dialog-Text aktualisieren
  const handleUpdateDialogueText = (text: string) => {
    if (!editMode || !selectedDialogueId || !localNPC.dialogues) return;
    
    const updatedDialogues = localNPC.dialogues.map(d => 
      d.id === selectedDialogueId ? { ...d, text } : d
    );
    const updatedNPC = { ...localNPC, dialogues: updatedDialogues };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `dialogue.${selectedDialogueId}.text`, dialogPreview);
    setDialogPreview(text);
  };

  // Antwortmöglichkeit hinzufügen
  const handleAddResponse = () => {
    if (!editMode || !selectedDialogueId || !localNPC.dialogues) return;
    
    const responseId = `response_${Date.now()}`;
    const updatedDialogues = localNPC.dialogues.map(d => {
      if (d.id === selectedDialogueId) {
        return {
          ...d,
          responses: [
            ...(d.responses || []),
            { id: responseId, text: 'Neue Antwort' }
          ]
        };
      }
      return d;
    });
    
    const updatedNPC = { ...localNPC, dialogues: updatedDialogues };
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `dialogue.${selectedDialogueId}.responses`, 
      localNPC.dialogues.find(d => d.id === selectedDialogueId)?.responses);
  };

  // Antwortmöglichkeit löschen
  const handleDeleteResponse = (dialogueId: string, responseId: string) => {
    if (!editMode || !localNPC.dialogues) return;
    
    const updatedDialogues = localNPC.dialogues.map(d => {
      if (d.id === dialogueId && d.responses) {
        return {
          ...d,
          responses: d.responses.filter(r => r.id !== responseId)
        };
      }
      return d;
    });
    
    const updatedNPC = { ...localNPC, dialogues: updatedDialogues };
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `dialogue.${dialogueId}.responses`, 
      localNPC.dialogues.find(d => d.id === dialogueId)?.responses);
  };

  // Antworttext aktualisieren
  const handleUpdateResponseText = (dialogueId: string, responseId: string, text: string) => {
    if (!editMode || !localNPC.dialogues) return;
    
    const updatedDialogues = localNPC.dialogues.map(d => {
      if (d.id === dialogueId && d.responses) {
        return {
          ...d,
          responses: d.responses.map(r => 
            r.id === responseId ? { ...r, text } : r
          )
        };
      }
      return d;
    });
    
    const updatedNPC = { ...localNPC, dialogues: updatedDialogues };
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `dialogue.${dialogueId}.response.${responseId}.text`, 
      localNPC.dialogues.find(d => d.id === dialogueId)?.responses?.find(r => r.id === responseId)?.text);
  };

  // Nächsten Dialog für eine Antwort festlegen
  const handleSetNextDialogue = (dialogueId: string, responseId: string, nextDialogueId: string) => {
    if (!editMode || !localNPC.dialogues) return;
    
    const updatedDialogues = localNPC.dialogues.map(d => {
      if (d.id === dialogueId && d.responses) {
        return {
          ...d,
          responses: d.responses.map(r => 
            r.id === responseId ? { ...r, nextDialogueId } : r
          )
        };
      }
      return d;
    });
    
    const updatedNPC = { ...localNPC, dialogues: updatedDialogues };
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `dialogue.${dialogueId}.response.${responseId}.nextDialogueId`, 
      localNPC.dialogues.find(d => d.id === dialogueId)?.responses?.find(r => r.id === responseId)?.nextDialogueId);
  };

  // Aktuell ausgewählter Dialog
  const selectedDialogue = localNPC.dialogues?.find(d => d.id === selectedDialogueId);

  return (
    <div className="space-y-6 p-4 bg-cyrus-dark-lighter rounded-md border border-cyrus-dark-lightest">
      <div className="flex justify-between items-center">
        <h2 className="text-xl font-semibold text-white">Dialoge</h2>
        {editMode && (
          <Button
            variant="outline"
            size="sm"
            onClick={handleAddDialogue}
            className="flex items-center gap-1 bg-cyrus-dark text-white border-cyrus-dark-lightest hover:bg-cyrus-dark-lighter"
          >
            <Plus className="h-4 w-4" /> Dialog hinzufügen
          </Button>
        )}
      </div>
      
      <div className="grid grid-cols-1 lg:grid-cols-3 gap-4">
        {/* Dialogliste */}
        <div className="lg:col-span-1">
          <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
            <CardContent className="p-3">
              <h3 className="text-md font-semibold text-white mb-3">Verfügbare Dialoge</h3>
              {localNPC.dialogues && localNPC.dialogues.length > 0 ? (
                <ul className="space-y-2 max-h-[300px] overflow-y-auto">
                  {localNPC.dialogues.map(dialogue => (
                    <li 
                      key={dialogue.id}
                      className={`p-2 rounded cursor-pointer flex justify-between items-center
                        ${selectedDialogueId === dialogue.id 
                          ? 'bg-[#007BFF] text-white' 
                          : 'bg-cyrus-dark-lighter text-gray-300 hover:bg-cyrus-dark-lightest'
                        }`}
                      onClick={() => setSelectedDialogueId(dialogue.id)}
                    >
                      <span className="truncate">{dialogue.text.substring(0, 25)}{dialogue.text.length > 25 ? '...' : ''}</span>
                      {editMode && (
                        <Button
                          variant="ghost"
                          size="sm"
                          onClick={(e) => {
                            e.stopPropagation();
                            handleDeleteDialogue(dialogue.id);
                          }}
                          className="h-6 w-6 p-0 hover:bg-red-500/20"
                        >
                          <Trash2 className="h-4 w-4 text-red-400" />
                        </Button>
                      )}
                    </li>
                  ))}
                </ul>
              ) : (
                <div className="text-center text-gray-400 py-4">
                  Keine Dialoge vorhanden
                </div>
              )}
            </CardContent>
          </Card>
        </div>
        
        {/* Dialog-Editor */}
        <div className="lg:col-span-2">
          {selectedDialogue ? (
            <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
              <CardContent className="p-4">
                <div className="space-y-4">
                  <div className="space-y-2">
                    <Label htmlFor="dialogue-text" className="text-white">Dialogtext</Label>
                    <Textarea
                      id="dialogue-text"
                      value={dialogPreview}
                      onChange={(e) => handleUpdateDialogueText(e.target.value)}
                      disabled={!editMode}
                      className="bg-cyrus-dark-lighter text-white border-cyrus-dark-lightest min-h-[100px]"
                    />
                  </div>
                  
                  <div>
                    <div className="flex justify-between items-center mb-2">
                      <Label className="text-white">Antwortmöglichkeiten</Label>
                      {editMode && (
                        <Button
                          variant="outline"
                          size="sm"
                          onClick={handleAddResponse}
                          className="flex items-center gap-1 bg-cyrus-dark text-white border-cyrus-dark-lightest hover:bg-cyrus-dark-lighter"
                        >
                          <Plus className="h-3 w-3" /> Antwort
                        </Button>
                      )}
                    </div>
                    
                    {selectedDialogue.responses && selectedDialogue.responses.length > 0 ? (
                      <ul className="space-y-3 max-h-[200px] overflow-y-auto p-1">
                        {selectedDialogue.responses.map(response => (
                          <li key={response.id} className="bg-cyrus-dark-lighter p-3 rounded-md">
                            <div className="flex flex-col gap-2">
                              <div className="flex items-start gap-2">
                                <Input
                                  value={response.text}
                                  onChange={(e) => handleUpdateResponseText(selectedDialogue.id, response.id, e.target.value)}
                                  disabled={!editMode}
                                  className="flex-1 bg-cyrus-dark text-white border-cyrus-dark-lightest"
                                />
                                {editMode && (
                                  <Button
                                    variant="ghost"
                                    size="sm"
                                    onClick={() => handleDeleteResponse(selectedDialogue.id, response.id)}
                                    className="h-8 w-8 p-0 hover:bg-red-500/20"
                                  >
                                    <Trash2 className="h-4 w-4 text-red-400" />
                                  </Button>
                                )}
                              </div>
                              
                              {editMode && (
                                <div className="flex items-center gap-2 mt-1">
                                  <Label className="text-sm text-gray-400 whitespace-nowrap">Verweis auf:</Label>
                                  <select
                                    value={response.nextDialogueId || ''}
                                    onChange={(e) => handleSetNextDialogue(selectedDialogue.id, response.id, e.target.value)}
                                    className="flex-1 text-sm bg-cyrus-dark text-white border border-cyrus-dark-lightest rounded-md p-1"
                                  >
                                    <option value="">Kein Verweis</option>
                                    {localNPC.dialogues
                                      ?.filter(d => d.id !== selectedDialogue.id)
                                      .map(d => (
                                        <option key={d.id} value={d.id}>
                                          {d.text.substring(0, 25)}{d.text.length > 25 ? '...' : ''}
                                        </option>
                                      ))
                                    }
                                  </select>
                                  <ArrowRight className="h-4 w-4 text-gray-400" />
                                </div>
                              )}
                            </div>
                          </li>
                        ))}
                      </ul>
                    ) : (
                      <div className="text-center text-gray-400 py-4 bg-cyrus-dark-lighter rounded-md">
                        Keine Antwortmöglichkeiten vorhanden
                      </div>
                    )}
                  </div>
                </div>
              </CardContent>
            </Card>
          ) : (
            <div className="flex items-center justify-center h-full bg-cyrus-dark rounded-md border border-cyrus-dark-lightest p-8">
              <p className="text-gray-400 text-center">
                Wählen Sie einen Dialog aus oder erstellen Sie einen neuen Dialog
              </p>
            </div>
          )}
        </div>
      </div>
    </div>
  );
};

export default Dialogues; 