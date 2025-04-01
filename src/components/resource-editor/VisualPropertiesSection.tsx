import { ResourceItem } from "../../types/fileTypes";
import { formatItemIconValue } from "../../utils/file/fileOperations";

interface VisualPropertiesSectionProps {
  localItem: ResourceItem;
  editMode: boolean;
  handleDataChange: (field: string, value: string | number | boolean) => void;
}

const VisualPropertiesSection = ({ localItem, editMode, handleDataChange }: VisualPropertiesSectionProps) => {
  // Funktion zum Ändern des Item-Icons mit korrekter Formatierung
  const handleIconChange = (value: string) => {
    const formattedIcon = formatItemIconValue(value);
    handleDataChange('itemIcon', formattedIcon);
  };

  // Extrahiere den reinen Iconnamen ohne die dreifachen Anführungszeichen
  const cleanIconName = localItem.fields?.specItem?.itemIcon?.replace(/^["']{1,3}|["']{1,3}$/g, '') || '';

  // Zeige, wie das Icon nach der Speicherung aussehen wird
  const formattedIconPreview = cleanIconName ? `"""${cleanIconName}"""` : '';

  return (
    <div className="mb-6">
      <h2 className="text-[#007BFF] text-lg font-semibold mb-2">Visual Properties</h2>
      <div className="grid grid-cols-2 gap-4">
        <div>
          <label htmlFor="item-icon" className="block text-sm font-medium">Item Icon</label>
          <input
            id="item-icon"
            type="text"
            value={cleanIconName}
            onChange={(e) => handleIconChange(e.target.value)}
            disabled={!editMode}
            className={`mt-1 block w-full p-2 border border-gray-300 rounded-md shadow-sm ${!editMode ? 'bg-gray-50' : ''}`}
          />
          <p className="mt-1 text-xs text-gray-500">
            Icon file in DDS format (e.g. itm_WeaAxeCurin2.dds)
          </p>
          {cleanIconName && (
            <p className="mt-1 text-xs text-blue-600">
              Wird gespeichert als: <code>{formattedIconPreview}</code>
            </p>
          )}
        </div>
      </div>
    </div>
  );
};

export default VisualPropertiesSection;
