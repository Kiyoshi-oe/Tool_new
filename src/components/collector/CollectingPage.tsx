import React, { useState, useEffect } from "react";
import CollectorTab from "./CollectorTab";
import { Button } from "../ui/button";
import { Upload, Save, Eye, Edit } from "lucide-react";
import { toast } from "sonner";
import { ResourceItem } from '../../types/fileTypes';

interface CollectingPageProps {
  onLoadResourceFile?: () => void; // Callback for the "Load Resource File" button
  editMode?: boolean; // Add editMode prop
  onToggleEditMode?: () => void; // Add toggle function prop
  availableItems?: ResourceItem[]; // Prop here added
}

// Erweitere den FC Typ mit der hideSidebar-Eigenschaft
interface CollectingPageComponent extends React.FC<CollectingPageProps> {
  hideSidebar?: boolean;
}

// Füge die TypeScript-Definition für window.electron hinzu
declare global {
  interface Window {
    electron: {
      openFileDialog: (options: any) => Promise<{ canceled: boolean, filePaths: string[] }>;
      readTextFile: (filePath: string) => Promise<{ content: string, error?: string }>;
      saveTextFile: (filePath: string, content: string) => Promise<{ success: boolean, error?: string }>;
    };
  }
}

// Komponente markiert, dass die Sidebar versteckt werden soll
const CollectingPage: CollectingPageComponent = ({ onLoadResourceFile, editMode = false, onToggleEditMode, availableItems = [] }) => {
  const [sContent, setSContent] = useState<string>("");
  const [isLoading, setIsLoading] = useState(false);
  const [isSaving, setIsSaving] = useState(false);
  const [unsavedChanges, setUnsavedChanges] = useState(false);
  const [sTxtPath, setSTxtPath] = useState<string>("");
  
  // Die hideSidebar-Eigenschaft, die von der Layout-Komponente erkannt wird
  CollectingPage.hideSidebar = true;
  
  // Example content based on the actual s.txt file
  const generateDefaultSContent = () => {
    return `// accessory.inc		
// Á¦·Ã È®·ü		
Accessory_Probability	// 1 / 10000 ±âÁØ	
{		
	10000	// 0 - 1
	10000	// 1 - 2
	6300	// 2 - 3
	4500	// 3 - 4
	3300	// 4  - 5
	2600	// 5 - 6
	2100	// 6 - 7
	1700	// 7 - 8
	1400	// 8 - 9
	1100	// 9 - 10
	900	// 10 - 11
	800	// 11 - 12
	600	// 12 - 13	
	500	// 13 - 14	
	400	// 14 - 15	
	300	// 15 - 16	
	200	// 16 - 17	
	100	// 17 - 18	
	50	// 18 - 19	
	10	// 19 - 20	
}			

// collecting.inc			
// Ã¤Áý±â Á¦·Ã È®·ü			
Collecting_Enchant			
{			
// 1 / 1000			
//	È®·ü		Á¦·Ã ·¹º§
	100		// 0
	100		// 1
	100		// 2
	100		// 3
	100		// 4	
	50		// 5
	40		// 6
	30		// 7
	20		// 8
	10		// 9
}			

Collecting_Item // Sum = 1000000
                           
{                                          
	II_SYS_SYS_SCR_SCUD             2000
	II_SYS_SYS_SCR_HOLY	            8000
	II_GEN_FOO_INS_STARCANDY        85000
	II_CHR_FOO_COO_REMANTIS         7500
	II_CHR_FOO_COO_BLUEREMANTIS     7500
	II_SYS_GLYPH_SHARD     			5000
	II_SYS_SYS_SCR_BXFLYI           4000
	II_SYS_SYS_SCR_BX1DBALLOON      4000
	II_SYS_SYS_SCR_BXSBEADS         4000
	II_GEN_GEM_CRAFTMATERIAL096     5000
	II_GEN_GEM_CRAFTMATERIAL093     5000
	II_GEN_GEM_CRAFTMATERIAL014     5000
	II_GEN_GEM_CRAFTMATERIAL074     5000
	II_GEN_GEM_CRAFTMATERIAL080     5000
	II_GEN_GEM_CRAFTMATERIAL016     5000
	II_GEN_GEM_CRAFTMATERIAL107     5000
	II_GEN_GEM_CRAFTMATERIAL346     30
	II_GEN_GEM_CRAFTMATERIAL349     30
	II_GEN_GEM_CRAFTMATERIAL351     30
	II_GEN_GEM_CRAFTMATERIAL352     30
	II_GEN_GEM_CRAFTMATERIAL353     30
	II_GEN_GEM_CRAFTMATERIAL356     30
	II_GEN_GEM_CRAFTMATERIAL357     30
	II_GEN_GEM_CRAFTMATERIAL358     30
	II_GEN_GEM_CRAFTMATERIAL359     30
	II_GEN_GEM_CRAFTMATERIAL361     30
	II_GEN_GEM_CRAFTMATERIAL362     30
	II_SYS_SYS_SCR_MINIWHEEL		318000
	II_SYS_SYS_SCR_WHEEL			150000
	II_CHP_COLLECTOR				368670
	II_SYS_SYS_SCR_SCRAPVACCUM		200
	II_SYS_SYS_SCR_SCRAPEARTHQUAKE	200
	II_SYS_SYS_SCR_SCRAPVOLCANO		200
	II_SYS_SYS_SCR_SCRAPLIGHTING	200
	II_SYS_SYS_SCR_SCRAPOCEAN		200
}


Collecting_PremiumItem
{
	II_SYS_SYS_SCR_BXCOLLPREM	1000000
}

Collecting_PremiumStatusItem
{
	II_SYS_SYS_SCR_BXCOLL		1000000
}`;
  };
  
  // Load the s.txt file
  const loadSFile = async () => {
    setIsLoading(true);
  
    try {
      // Prüfe, ob die Electron API verfügbar ist
      if (!window.electron) {
        console.error("Electron API ist nicht verfügbar");
        toast.error("Electron API ist nicht verfügbar - Dateioperationen werden nicht funktionieren");
        setIsLoading(false);
        
        // Verwende den Beispielinhalt als Fallback
        setSContent(generateDefaultSContent());
        return;
      }
      
      // Öffne den Dateiauswahldialog, um die s.txt Datei auszuwählen
      const result = await window.electron.openFileDialog({
        title: "Select s.txt file",
        defaultPath: "",
        filters: [
          { name: "Text Files", extensions: ["txt"] }
        ],
        properties: ["openFile"]
      });
      
      if (result.canceled || result.filePaths.length === 0) {
        setIsLoading(false);
        return;
      }
      
      const filePath = result.filePaths[0];
      setSTxtPath(filePath); // Speichere den Pfad zur s.txt Datei
      
      // Lese den Inhalt der s.txt Datei
      const fileResult = await window.electron.readTextFile(filePath);
      
      if (fileResult.error) {
        toast.error(`Error reading file: ${fileResult.error}`);
        setIsLoading(false);
        return;
      }
      
      setSContent(fileResult.content);
      toast.success(`s.txt file loaded: ${filePath}`);
      setUnsavedChanges(false);
    } catch (error) {
      console.error("Error loading s.txt file:", error);
      toast.error("Error loading s.txt file");
      
      // Verwende den Beispielinhalt als Fallback
      setSContent(generateDefaultSContent());
    } finally {
      setIsLoading(false);
    }
  };
  
  // Save the s.txt file
  const handleSave = async (content: string) => {
    if (!sTxtPath) return;
    
    // Prüfe, ob die Electron API verfügbar ist
    if (!window.electron) {
      console.error("Electron API ist nicht verfügbar");
      toast.error("Electron API ist nicht verfügbar - Dateioperationen werden nicht funktionieren");
      return;
    }
    
    setIsSaving(true);
    
    try {
      // Speichere die Änderungen in die s.txt-Datei
      const result = await window.electron.saveTextFile(sTxtPath, content);
      
      if (result.success) {
        toast.success("s.txt erfolgreich gespeichert");
        setUnsavedChanges(false);
      } else {
        toast.error(`Fehler beim Speichern: ${result.error}`);
      }
    } catch (error) {
      console.error("Error saving s.txt:", error);
      toast.error("Fehler beim Speichern der s.txt-Datei");
    } finally {
      setIsSaving(false);
    }
  };
  
  // Load the file automatically on first load
  useEffect(() => {
    // Prüfe, ob die Electron API verfügbar ist
    if (typeof window !== 'undefined' && window.electron) {
      // Automatisch die Datei laden
      loadSFile();
    } else {
      console.warn("Electron API ist nicht verfügbar - Verwende Beispieldaten");
      setIsLoading(false);
      setSContent(generateDefaultSContent());
    }
  }, []);
  
  // Wenn der Komponente als Mount geladen wird oder der Tab gewechselt wird, lade die Datei
  useEffect(() => {
    // Wir können dem onLoadResourceFile-Callback vertrauen, um zu wissen, wann der Tab aktiviert wurde
    if (onLoadResourceFile && typeof window !== 'undefined' && window.electron) {
      loadSFile(); // Die s.txt Datei sofort laden, wenn die Komponente angezeigt wird
    } else if (onLoadResourceFile) {
      // Wenn die Electron API nicht verfügbar ist, verwende Beispielinhalt
      if (!sContent) {
        setSContent(generateDefaultSContent());
      }
    }
  }, [onLoadResourceFile]);
  
  return (
    <div className="collecting-page">
      <div className="flex justify-between mb-6">
        {/* Edit Mode Toggle Button wurde entfernt, da er bereits in der Navigationsleiste verfügbar ist */}
      </div>
      
      {isLoading ? (
        <div className="flex justify-center p-12">
          <div className="animate-spin rounded-full h-12 w-12 border-t-2 border-b-2 border-primary"></div>
        </div>
      ) : (
        sContent ? (
          <CollectorTab 
            fileContent={sContent}
            onSave={handleSave}
            editMode={editMode}
            availableItems={availableItems}
          />
        ) : (
          <div className="flex flex-col items-center justify-center p-12 text-muted-foreground">
            <p className="mb-4">No s.txt file loaded</p>
            <Button onClick={loadSFile} variant="outline" className="flex items-center bg-cyrus-blue hover:bg-cyrus-blue/90 text-white">
              <Upload className="mr-2 h-4 w-4" />
              Load File
            </Button>
          </div>
        )
      )}
    </div>
  );
};

export default CollectingPage; 