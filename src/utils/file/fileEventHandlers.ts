/**
 * Event-Handler für Datei-Aktualisierungen
 * Diese Datei enthält Funktionen, die auf Änderungen an Dateien reagieren und die UI aktualisieren
 */
// Fallback für Benachrichtigungen, falls react-toastify nicht verfügbar ist
const toast = {
  success: (message: string, options?: any) => {
    console.log(`Toast Success: ${message}`);
    // Prüfe ob die globale toast-Funktion verfügbar ist
    if ((window as any).toast?.success) {
      (window as any).toast.success(message, options);
    } else {
      // Verwende einfachen Alert als Fallback
      // alert(message);
      
      // Oder erstelle ein temporäres Benachrichtigungselement
      showTemporaryNotification(message, 'success');
    }
  },
  error: (message: string, options?: any) => {
    console.error(`Toast Error: ${message}`);
    if ((window as any).toast?.error) {
      (window as any).toast.error(message, options);
    } else {
      // alert(`Fehler: ${message}`);
      showTemporaryNotification(message, 'error');
    }
  }
};

/**
 * Zeigt eine temporäre Benachrichtigung an, falls toast nicht verfügbar ist
 */
const showTemporaryNotification = (message: string, type: 'success' | 'error' = 'success'): void => {
  // Erstelle Benachrichtigungs-Element
  const notification = document.createElement('div');
  notification.style.position = 'fixed';
  notification.style.bottom = '20px';
  notification.style.right = '20px';
  notification.style.padding = '12px 20px';
  notification.style.borderRadius = '4px';
  notification.style.backgroundColor = type === 'success' ? '#4CAF50' : '#F44336';
  notification.style.color = 'white';
  notification.style.boxShadow = '0 2px 10px rgba(0, 0, 0, 0.2)';
  notification.style.zIndex = '9999';
  notification.style.opacity = '0';
  notification.style.transition = 'opacity 0.3s ease-in-out';
  notification.textContent = message;
  
  // Füge zum DOM hinzu
  document.body.appendChild(notification);
  
  // Einblenden
  setTimeout(() => {
    notification.style.opacity = '1';
  }, 10);
  
  // Nach einigen Sekunden ausblenden und entfernen
  setTimeout(() => {
    notification.style.opacity = '0';
    setTimeout(() => {
      if (notification.parentNode) {
        notification.parentNode.removeChild(notification);
      }
    }, 300);
  }, 3000);
};

/**
 * Initialisiert die Event-Listener für Datei-Aktualisierungen
 */
export const initFileEventListeners = (): void => {
  console.log('Initialisiere Datei-Event-Listener');
  
  // Event-Listener für PropItem-Aktualisierungen
  window.addEventListener('propItemsUpdated', (event: any) => {
    const propItems = event.detail || [];
    console.log(`PropItems-Update empfangen: ${propItems.length} Items`);
    
    handlePropItemsUpdated(propItems);
  });
  
  // Event-Listener für DefineItem-Aktualisierungen
  window.addEventListener('defineItemsUpdated', (event: any) => {
    const defineItems = event.detail || [];
    console.log(`DefineItems-Update empfangen: ${defineItems.length} Items`);
    
    handleDefineItemsUpdated(defineItems);
  });
  
  // Event-Listener für MdlDyna-Aktualisierungen
  window.addEventListener('mdlDynaItemsUpdated', (event: any) => {
    const mdlDynaItems = event.detail || [];
    console.log(`MdlDynaItems-Update empfangen: ${mdlDynaItems.length} Items`);
    
    handleMdlDynaItemsUpdated(mdlDynaItems);
  });
};

/**
 * Behandelt Aktualisierungen an PropItems
 */
const handlePropItemsUpdated = (propItems: any[]): void => {
  if (!propItems || propItems.length === 0) return;
  
  // Zeige eine Toast-Nachricht an, dass PropItems aktualisiert wurden
  toast.success(`PropItems erfolgreich aktualisiert (${propItems.length} Items)`, {
    position: 'bottom-right',
    autoClose: 3000
  });
  
  // Aktualisiere UI-Komponenten, die PropItems anzeigen
  updateResourceEditors('propItem', propItems);
};

/**
 * Behandelt Aktualisierungen an DefineItems
 */
const handleDefineItemsUpdated = (defineItems: any[]): void => {
  if (!defineItems || defineItems.length === 0) return;
  
  // Zeige eine Toast-Nachricht an, dass DefineItems aktualisiert wurden
  toast.success(`DefineItems erfolgreich aktualisiert (${defineItems.length} Items)`, {
    position: 'bottom-right',
    autoClose: 3000
  });
  
  // Aktualisiere UI-Komponenten, die DefineItems anzeigen
  updateResourceEditors('defineItem', defineItems);
};

/**
 * Behandelt Aktualisierungen an MdlDynaItems
 */
const handleMdlDynaItemsUpdated = (mdlDynaItems: any[]): void => {
  if (!mdlDynaItems || mdlDynaItems.length === 0) return;
  
  // Zeige eine Toast-Nachricht an, dass MdlDynaItems aktualisiert wurden
  toast.success(`Modell-Dateien erfolgreich aktualisiert (${mdlDynaItems.length} Items)`, {
    position: 'bottom-right',
    autoClose: 3000
  });
  
  // Aktualisiere UI-Komponenten, die MdlDynaItems anzeigen
  updateResourceEditors('mdlDyna', mdlDynaItems);
};

/**
 * Aktualisiert Resource-Editoren für einen bestimmten Ressourcentyp
 */
const updateResourceEditors = (resourceType: string, items: any[]): void => {
  // Finde alle ResourceEditor-Komponenten auf der Seite
  const editors = document.querySelectorAll<HTMLElement>('[data-resource-editor]');
  
  editors.forEach(editor => {
    const editorType = editor.getAttribute('data-resource-type');
    if (editorType === resourceType) {
      // Setze einen Timestamp für die Aktualisierung
      editor.setAttribute('data-last-update', Date.now().toString());
      
      // Falls die Komponente eine refresh-Methode hat
      const refreshMethod = editor.getAttribute('data-refresh-method');
      if (refreshMethod && (window as any)[refreshMethod]) {
        try {
          (window as any)[refreshMethod](editor, items);
        } catch (error) {
          console.error(`Fehler beim Aktualisieren des Editors mit Methode ${refreshMethod}:`, error);
        }
      }
      
      // Trigger ein Custom-Event auf dem Element
      const updateEvent = new CustomEvent('resourceUpdated', { detail: { type: resourceType, items } });
      editor.dispatchEvent(updateEvent);
    }
  });
  
  // Falls React-Komponenten verwendet werden, können wir auch globale State-Updates auslösen
  if ((window as any).appState?.updateResources) {
    (window as any).appState.updateResources(resourceType, items);
  }
};

// Initialisiere die Event-Listener beim Import dieses Moduls
if (typeof window !== 'undefined') {
  // Verzögere die Initialisierung, damit die Seite vollständig geladen ist
  setTimeout(() => {
    initFileEventListeners();
  }, 500);
} 