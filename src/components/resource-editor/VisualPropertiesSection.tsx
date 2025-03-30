import { ResourceItem } from "../../types/fileTypes";

interface VisualPropertiesSectionProps {
  localItem: ResourceItem;
  editMode: boolean;
  handleDataChange: (field: string, value: string | number | boolean) => void;
}

const VisualPropertiesSection = ({ localItem, editMode, handleDataChange }: VisualPropertiesSectionProps) => {
  return (
    <div className="mb-6">
      <h2 className="text-[#007BFF] text-lg font-semibold mb-2">Visual Properties</h2>
      {/* Visual Properties Komponente - leer */}
    </div>
  );
};

export default VisualPropertiesSection;
